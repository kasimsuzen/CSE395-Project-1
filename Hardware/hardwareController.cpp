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

void b(){
	std::cout << "b\n";
}

void c(){
	std::cout << "c\n";
}
int main(int argc,char **argv){
	float latitude=0,longitude=0,epsilon = 0.0010,currentLat,currentLong;
	int tempAngle=0,tempWifi=0;
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
	ledErrorOutput(RESPOND_ERROR);
	while(1){
		parseGPSData(&latitude,&longitude,5);
		mainMutex.lock();
		sprintf(temp,"%d %f %f",findLocal(),latitude,longitude);
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
		sep = split(recvMessage,' ');
		mainMutex.unlock();
		if(sep.size() == 4){
		// outdoor 
			latitude = atof(sep[1].c_str());
			longitude = atof(sep[2].c_str());
			tempAngle = atof(sep[3].c_str());
			servoController(tempAngle,0);
			
			while(1){
				parseGPSData(&currentLat,&currentLong);
				if(fabs(currentLat - latitude) <= epsilon && fabs(currentLong - longitude) <= epsilon)
					break;
				servoController(tempAngle,0);
				usleep(50000);
			}
			servoController(tempAngle,1);
		}
		else if(sep.size() == 3){
		//indoor
			tempWifi = atof(sep[1].c_str());
			tempAngle = atof(sep[2].c_str());
			servoController(tempAngle,0);
			while(1){
				if(tempWifi == findLocal())
					break;
				servoController(tempAngle,0);	
			}
			servoController(tempAngle,1);
		}
		// will wait new target
		else if(sep.size() == 2 && sep[1].compare("finish") == 0)
 			continue;

	}
	threads.join_all();
	return 0;
}