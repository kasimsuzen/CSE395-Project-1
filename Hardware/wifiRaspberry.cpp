#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "hardware.h"
//smart


using namespace std;

int averageVector(const vector<int> &values);

int calculateNearest(const vector< vector< int> > values);
/*
int main(int argc, char const *argv[])
{
	char input;
	while(1)
	{
		cout << "enter your input s>>cont.  -- q>>quit" << endl;
		cin >> input;
		if(input == 's')
			findLocal("");
		else if(input == 'q')
			break;
	}
	return 0;
}*/

int findLocal()
{
    string temp;
    int counter = 0;
	string after;
    int flag = 0;

    vector< vector < int > > dbs(11);

    for (int i = 0; i < dbs.size(); ++i)
    	dbs[i].push_back(0);



	FILE *fp;
	char path[1035];

	/* Open the command for reading. */
	fp = popen("sudo iwlist wlan0 scan|grep -o -e 'Signal level=.*' -e 'ESSID:.*'", "r");
	if (fp == NULL) 
	{
		printf("Failed to run command\n" );
		exit(1);
	}

	while(fgets(path, sizeof(path)-1, fp) != NULL)
  {	
    	string temp(path);
      //cout << temp;

			if(strlen(path) > 0 && temp[0] == 'E')
			{
				//readESSID 
				vector<string> res = split(temp, '"');
				//outfile << res[1] << " ";
				after = res[1];
	
			}
			else if(strlen(path) > 0 && temp[0] == 'S')
			{
				vector<string> res = split(temp, '=');

				if(atoi(after.c_str()) > 0 && atoi(after.c_str()) < 12)
				{
					dbs[atoi(after.c_str()) -1 ].push_back(atoi(res[1].c_str()));
				}

			}
	}   
	
	int nearest = calculateNearest(dbs);
	cout << "You are about " << nearest << " area" << endl;
	
	/* close */
		pclose(fp);
	return nearest;
}

//find nearest as real (return + 1)
int calculateNearest(const vector< vector< int> > values)
{
	int maxArea = -9999, area = 0;
	
	for (int i = 0; i < values.size(); ++i)
	{
		int currentArea = averageVector(values[i]);
		if(currentArea > maxArea ){
			maxArea = currentArea;
			area = i;
		}
		//cout << currentArea << "\t" << i+1 << endl;
	}
	return area + 1;
}


//calc avg single vector elements
int averageVector(const vector<int> &values)
{
	int sum = 0;
	for (int i = 1; i < values.size(); ++i)
	{
		sum += values[i];
	}
	int size = static_cast<int>(values.size())-1;
	if (size == 0) size = 1;
	return static_cast<int>(sum / size);
}
