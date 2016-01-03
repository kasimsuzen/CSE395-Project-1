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
boost::mutex wifiMutex;
string sendMessage;
string recvMessage;
int indoorArea;

int main(int argc,char **argv){
	float latitude=0,longitude=0,epsilon = 0.0001,currentLat,currentLong;
	int tempAngle=0,tempWifi=0,tempArea=0,previousArea=-1;
	char temp[250];
	vector<string> sep;
	indoorArea = -1;
	boost::thread_group threads;

	servoController(0,1,0);

	memset(temp,'\0',250);

	while(checkInternetAccess() == -1){
		usleep(500000);
	}
	
	threads.create_thread(boost::bind(clientCube));
	threads.create_thread(boost::bind(findLocal));
	while(1){
		parseGPSData(&latitude,&longitude,2);
		mainMutex.lock();
		wifiMutex.lock();
		sprintf(temp,"%d %f %f",indoorArea,latitude,longitude);
		previousArea = indoorArea;
		wifiMutex.unlock();
		cout << "temp " << temp << endl;
		sendMessage.append(temp);
		mainMutex.unlock();
		usleep(500000);
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
			cout << " outer server message " << latitude << " " << longitude << " " << tempAngle << endl;
			while(1){
				parseGPSData(&currentLat,&currentLong);
				cout << "inner server message " << latitude << " " << longitude << " " << tempAngle << " current " << currentLat << " " << currentLong << endl;
				
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
			cout << "step 1 " << endl; 
			while(1){
				cout << "step 2 " << endl;
				wifiMutex.lock();
				tempArea = indoorArea;
				wifiMutex.unlock();

				servoController(tempAngle,0,tempArea);
				cout << "step 22 " << previousArea << " " << tempArea << endl;
				mainMutex.lock();
				wifiMutex.lock();
				tempArea = indoorArea;
				wifiMutex.unlock();
				if(tempArea != previousArea || tempWifi == tempArea){
					previousArea = tempArea;
					sendMessage.clear();
					sprintf(temp,"%d %f %f",tempArea,latitude,longitude);
					sendMessage.append(temp);
					cout << "step 3 " << endl;
					if(tempWifi == tempArea){
						mainMutex.unlock();
						cout << "step 4 " << endl;
						memset(temp,'\0',250);
						break;
					}
					mainMutex.unlock();
				}
				else
					mainMutex.unlock();

			}
			cout << "step 5 " << endl;
			servoController(tempAngle,1,tempArea);
		}
		// will wait new target
		else if(sep.size() == 2 && sep[1].compare("finish") == 0)
 			continue;
		cout << "step 6 " << endl;
	}
	threads.join_all();
	return 0;
}
