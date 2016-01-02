#include <iostream>
#include <string>
#include "hardware.h"
#include "../Server/network.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <unistd.h>
#include <cstring>

using namespace std;
boost::mutex mainMutex;
string sendMessage;
string recvMessage;
int indoorArea;

int main(int argc,char **argv){
	float latitude=0,longitude=0,epsilon = 0.0001,currentLat,currentLong;
	int tempAngle=0,tempWifi=0,tempArea=0,previousArea=-1;
	char temp[250];
	vector<string> sep;
	boost::thread_group threads;

	memset(temp,'\0',250);

	ledErrorOutput(INTERNET_ACCESS_ERROR);
	while(checkInternetAccess() == -1){
		usleep(500000);
	}
	ledErrorOutput(-1 * INTERNET_ACCESS_ERROR);
	
	threads.create_thread(boost::bind(clientCube));
	threads.create_thread(boost::bind(findLocal));
	ledErrorOutput(RESPOND_ERROR);
	while(1){
		parseGPSData(&latitude,&longitude,5);
		mainMutex.lock();
		sprintf(temp,"%d %f %f",indoorArea,latitude,longitude);
		previousArea = indoorArea;
		cout << "temp " << temp << endl;
		sendMessage.append(temp);
		mainMutex.unlock();
		mainMutex.lock();
		if(!recvMessage.empty()){
		cout << recvMessage << endl;
			if(recvMessage.find("yes") != string::npos){
				mainMutex.unlock();
				break;
			}
		}
		mainMutex.unlock();
		sleep(1);
		memset(temp,'\0',250);
	}
	ledErrorOutput(-1 * RESPOND_ERROR);
	cout << "after init " << endl; 
	while(1){
		// waiting command from interface
		while(1){
			mainMutex.lock();
			if(!recvMessage.empty()){
				mainMutex.unlock();
				break;
			}
			mainMutex.unlock();
			usleep(500000);
		}

		// if command came
		mainMutex.lock();
		cout << recvMessage << endl;
		sep = split(recvMessage,' ');
		recvMessage.clear();
		mainMutex.unlock();
		cout << sep.size();
		for(int a =0 ; a < sep.size(); ++a)
			cout << "sep " << a << "  " << sep[a] << endl;
		if(sep.size() == 4){
		// outdoor 
			latitude = atof(sep[1].c_str());
			longitude = atof(sep[2].c_str());
			tempAngle = atof(sep[3].c_str());
			servoController(tempAngle,0,-2);
			
			while(1){
				parseGPSData(&currentLat,&currentLong);
				if(fabs(currentLat - latitude) <= epsilon && fabs(currentLong - longitude) <= epsilon){
					mainMutex.lock();
					sendMessage.clear();
					sprintf(temp,"-1 %f %f",latitude,longitude);
					sendMessage.append(temp);
					mainMutex.unlock();
					memset(temp,'\0',250);
					break;
				}
				servoController(tempAngle,0,-2);
				usleep(50000);
			}
			servoController(tempAngle,1,-2);
		}
		else if(sep.size() == 3){
		//indoor
			tempWifi = atof(sep[1].c_str());
			tempAngle = atof(sep[2].c_str());
			while(1){
				mainMutex.lock();
				tempArea = indoorArea;
				mainMutex.unlock();
				servoController(tempAngle,0,tempArea);
				mainMutex.lock();
				if(indoorArea != previousArea){
					sendMessage.clear();
					sprintf(temp,"%d %f %f",indoorArea,latitude,longitude);
					sendMessage.append(temp);
					if(tempWifi == indoorArea){
						mainMutex.unlock();
						memset(temp,'\0',250);
						break;
					}
					mainMutex.unlock();
				}
				else
					mainMutex.unlock();

			}
			servoController(tempAngle,1,tempArea);
		}
		// will wait new target
		else if(sep.size() == 2 && sep[1].compare("finish") == 0)
 			continue;

	}
	threads.join_all();
	return 0;
}
