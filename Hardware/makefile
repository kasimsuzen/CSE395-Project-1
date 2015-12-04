CC= g++
CFLAGS= -Wall
LDFLAGS= -pthread -lm
SOURCES= *.cpp *.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= $(SOURCES).exe

all: hardwareee

hardwareee:
	$(CC) hardwareController.cpp motorChange.c GPS/gpsDataParser.cpp GPS/readGPS.c GPS/rs232.c compassController/compassControl.c ../Server/internetAccess.cpp ../Server/client.cpp $(LDFLAGS) -o hard
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o core *.core $(EXECUTABLE)