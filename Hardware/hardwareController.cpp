#include <iostream>
#include <string>
#include "hardware.h"
#include "../Server/network.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
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
	double n,k;
	int a=0,temp=200;
	boost::thread_group threads;
	
	//a.create_thread(boost::bind(headingAngle));
	//a.create_thread(boost::bind(servoController,180,1));
	threads.create_thread(boost::bind(clientCube));
	cout << "after thread " << endl; 
	while(a == 0){
		cout << "inside while";
		servoController(temp,0);
		n = headingAngle() - temp;
		k = 360 - abs(n);
		boost::this_thread::sleep( boost::posix_time::millisec(1000));
		headingAngle();
		if( abs(n) <= 15 && k <= 15){
			//a = 1;
			servoController(temp,1);
			cout << "before sleep" << endl;	
			boost::this_thread::sleep( boost::posix_time::millisec(1000));
			temp = (temp + 50) % 360;
			cout << "after sleep "<< temp << endl;	
		}

	}
	threads.join_all();
	return 0;
}