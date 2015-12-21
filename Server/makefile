CC= g++ 
CFLAGS= -Wall -std=c++11
LDFLAGS= -lboost_system -lboost_date_time -lboost_thread -lm
SOURCES= *.cpp *.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= $(SOURCES)

all: serverG1 serverG8 clientDeviceG1 clientInterfaceG1 clientDeviceG8 clientInterfaceG8

serverG1:
	$(CC) $(CFLAGS) -D GROUP1 server.cpp internetAccess.cpp $< $(LDFLAGS) -o $@

serverG8:
	$(CC) $(CFLAGS) -D GROUP8 server.cpp internetAccess.cpp $< $(LDFLAGS) -o $@

clientDeviceG1:
	$(CC) $(CFLAGS) -D DEVICE -D GROUP1 client.cpp internetAccess.cpp $< $(LDFLAGS) -o $@

clientInterfaceG1:
	$(CC) $(CFLAGS) -D INTERFACE -D GROUP1 client.cpp internetAccess.cpp $< $(LDFLAGS) -o $@

clientDeviceG8:
	$(CC) $(CFLAGS) -D DEVICE -D GROUP8 client.cpp internetAccess.cpp $< $(LDFLAGS) -o $@

clientInterfaceG8:
	$(CC) $(CFLAGS) -D INTERFACE -D GROUP8 client.cpp internetAccess.cpp $< $(LDFLAGS) -o $@

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o server clientDevice clientInterface
