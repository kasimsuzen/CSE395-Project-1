CC= g++
CFLAGS= -c -Wall -std=c++11 -D GROUP8 -D DEVICE
LDFLAGS= -lm -lboost_system -lboost_date_time -lboost_thread -lpthread -lstdc++
SOURCES=
OBJECTS= build/gpsDataParser.o build/readGPS.o build/rs232.o build/motorChange.o build/compassControl.o build/hardwareController.o build/client.o 
EXECUTABLE= hard

all: Gps Servo Compass Hardware Client Move Link
	
Move:
	mv gpsDataParser.o readGPS.o rs232.o motorChange.o compassControl.o hardwareController.o client.o build/

Link:
	$(CC) $(OBJECTS) $(LDFLAGS) -o hard

Gps:
	$(CC) $(CFLAGS) GPS/gpsDataParser.cpp GPS/readGPS.c GPS/rs232.c 

Servo:
	$(CC) $(CFLAGS) motorChange.cpp

Compass:
	$(CC) $(CFLAGS) compassController/compassControl.c

Hardware:
	$(CC) $(CFLAGS) hardwareController.cpp

Client:
	$(CC) $(CFLAGS) ../Server/client.cpp

clean:
	-rm -f *.o core *.core $(EXECUTABLE)
