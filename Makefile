CC=g++
CFLAGS=-c -Wall -Wextra -Wold-style-cast
LDFLAGS=
SOURCES=$(shell find -name "*.cpp")
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=SFCoding

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
