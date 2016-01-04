CC= g++ 
CFLAGS=-Wall -std=c++11
LDFLAGS=-lboost_system -lboost_date_time -lboost_thread -lm -lpthread
SOURCES= *.cpp *.cS
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= $(SOURCES)

all: server clientDevice clientInterface

server:
	$(CC) $(CFLAGS) server.cpp $< $(LDFLAGS) -o $@

clientDevice:
	$(CC) $(CFLAGS) -D DEVICE client.cpp $< $(LDFLAGS) -o $@

clientInterface:
	$(CC) $(CFLAGS) -D INTERFACE client.cpp $< $(LDFLAGS) -o $@

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o server clientDevice clientInterface
