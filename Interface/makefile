CC= g++
CFLAGS= -c -Wall
LDFLAGS=
SOURCES= *.cpp *.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= $(SOURCES).exe

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o core *.core $(EXECUTABLE)