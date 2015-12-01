CC= g++
CFLAGS= -Wall
LDFLAGS=
SOURCES= *.cpp *.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= $(SOURCES)

all: server client

server:
	$(CC) $(CFLAGS) server.cpp internetAccess.cpp $< -o $@

client:
	$(CC) $(CFLAGS) client.cpp internetAccess.cpp $< -o $@

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o server client