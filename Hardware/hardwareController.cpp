#include <iostream>
#include <string>
#include "hardware.h"
#include "../Server/network.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
using namespace std;
boost::mutex mainMutex;
string interfaceMessage;
string recvMessage;

void b(){
	std::cout << "b\n";
}

void c(){
	std::cout << "c\n";
}
int main(int argc,char **argv){
	boost::thread_group a;
	
	a.create_thread(boost::bind(headingAngle));
	a.create_thread(boost::bind(servoController,180,1));
	a.create_thread(boost::bind(clientCube));
	a.join_all();
	return 0;
}