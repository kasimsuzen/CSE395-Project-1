# CSE395-Project-1
This repository is for CSE395 course of Gebze Technical University Computer engineering Faculty 

Raspberry B+ Pin Layout

|    Description | Pin Number | Pin Number | Description    |
|---------------:|------------|------------|----------------|
| GPS VCC        | 1          | 2          | Servo 0 VCC    |
| Compass SDA    | 3          | 4          | Servo 1 VCC    |
| Compass SCL    | 5          | 6          | Servo 0 Ground |
| Servo 0 PWM    | 7          | 8          | GPS RX         |
| GPS Ground     | 9          | 10         | GPS TX         |
| Servo 1 PWM    | 11         | 12         |                |
|                | 13         | 14         | Servo 1 Ground |
| Compass VCC    | 17         | 18         |                |
| Compass Ground | 25         | 26         |                |
| LED Pin 1 Mode | 33         | 34         |                |
| LED Pin 2 Mode | 35         | 36         |                |
| LED Pin 3 Mode | 37         | 39         |                |

## Installing server dependencies
`$ sudo apt-get install libboost-all-dev ssh make gcc g++ git`

## Compiling and running server
`$ sudo make server`

`$ nohup ./server >> serverLog.txt &`

## Instaling hardware dependencies

This steps written for raspberries running raspbian jessie

`$ sudo apt-get install libi2c-dev i2c-tools python-smbus g++ gcc git gpsd gpsd-clients python-gps libboost-all-dev`

`$ git clone git://git.drogon.net/wiringPi`

`$ cd wiringPi`

`$ git pull origin`

`$ cd wiringPi`

`$ ./build`

To use i2c in raspberry this changes has to be made

`$ sudo nano /etc/modrobe.d/raspi-blacklist.conf`

if the file is empty you can skip this step, but if there is a line consisting i2c-bcm2708 add '#' start of the line

`$ sudo nano /etc/modules`

Add this two line to end of the file

i2c-dev
i2c-bcm2708

`$ sudo nano /boot/config.txt`

Add this two line to end of the file

dtparam=i2c_arm=on
dtparam=i2c1=on

After all this changes made reboot the raspberry

##How To compile hardware code

`$ cd PATH_TO_PROJECT_ROOT/Hardware`
`$ make all `

Application run like this(sudo needed for write/listen/add /dev/)

`$ sudo ./navigator`

# Interface

## Compile and Configure
Inteface wrote using qt so we will need it [Qt link](http://www.qt.io/download-open-source/)

### In windows 
Under windows you will need a C++ compiler [which you can find here](http://www.mingw.org/download/installer)

This lines should add qtpro file under the project

LIBS += C:\MinGW\lib\libws2_32.a
LIBS += C:\MinGW\lib\libwsock32.a

You also need boost, can be download boost from [here](http://sourceforge.net/projects/boost/files/boost/1.60.0/)
`$ cd PATH_TO_BOOST_INSTALL/`
`$ bootstrap.bat mingw`
`$ b2 install --prefix= c:/installation/path toolset=gcc`

After compile and configure boost also add this lines to qtpro file 

INCLUDEPATH += C:/boost_1_60_0

LIBS += -LC:/boost_1_60_0/stage/lib/ \

-lboost_system-mgw48-1_60 \

-lboost_date_time-mgw48-mt-1_60 \

-lboost_thread-mgw48-mt-1_60

### In Linux
You will need boost 
sudo apt-get install libboost-all-dev