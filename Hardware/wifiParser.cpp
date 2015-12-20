//
//  main.cpp
//  wifiParser
//
//  Created by Ali Kürşat Şahin on 29.11.2015.
//  Copyright © 2015 Ali Kürşat Şahin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>

// I don't recommend using the std namespace in production code.
// For ease of reading here.
using namespace std;

#define SIGNAL_STRENGTHS 0
#define SIGNAL_SEEK_COUNT 1

#define AREA_COUNT 11

// You could also take an existing vector as a parameter.
vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}

bool parseWifiViaESSID(string arg1, int* ESSID, int* signalStrength){
    vector<string> sep = split(arg1, ' ');

    if(atoi(sep[1].c_str()) >= 1 && atoi(sep[1].c_str()) <= AREA_COUNT ){
        *ESSID = atoi(sep[1].c_str());
        *signalStrength = atoi(sep[0].c_str());
        return true;
    }
    return false;
}

bool parseWifi (string arg1, string* MACAdress, int* signalStrength){

    vector<string> sep = split(arg1, ' ');

    if(sep[0].compare("00:0C:E6:12:3A:95") == 0){
        *MACAdress = sep[0].c_str();
        *signalStrength = atoi(sep[1].c_str());
        return true;
    }
    return false;
}


int main(int argc, char **argv) {
    int signalStrength=0;
    int ESSID=0;
    int nearestArea=0;
    int mostStrengtSignal=0;

    int sumOfApSignals[AREA_COUNT][2]={0};
    int avgOfApSignals[AREA_COUNT];

    string line = "", MACAdress= "00:00:00:00:00:00";

    ifstream myfile ("point-0.txt");

    vector<int> node;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            if(parseWifiViaESSID(line, &ESSID, &signalStrength)){
                sumOfApSignals[ESSID-1][SIGNAL_STRENGTHS] += signalStrength;
                ++sumOfApSignals[ESSID-1][SIGNAL_SEEK_COUNT];
            }

            /*
            if(parseWifi(line, &MACAdress, &signalStrength)){

                node.push_back(signalStrength);

                cout << "MAC = " << MACAdress << "\t" << "Signal Strength = "<< signalStrength << endl;
            }
            */

        }

        myfile.close();
    }

    // Calculate avgOfApSignals from sumOfApSignals
    for(int i = 0; i < AREA_COUNT; ++i){
        if(sumOfApSignals[i][1] != 0){
            avgOfApSignals[i]=sumOfApSignals[i][SIGNAL_STRENGTHS]/sumOfApSignals[SIGNAL_SEEK_COUNT][1];
        } else {
            avgOfApSignals[i]= -100;
        }
        cout << "Area_" << i+1 << " :" <<  avgOfApSignals[i] << endl;
    }

    // Get max_element of average_signal_strengts_of_defined_areas
    mostStrengtSignal = *std::max_element(avgOfApSignals, avgOfApSignals+AREA_COUNT);

    // Get index of mostStrengthSignal, that means which area we include on the map
    nearestArea = 1 + std::distance(avgOfApSignals, std::find(avgOfApSignals, avgOfApSignals + AREA_COUNT, mostStrengtSignal));

    //
    cout << "Most strength signal is : " <<  mostStrengtSignal << endl;

    cout << "Nearest area is :" << nearestArea << endl;

    return 0;

}