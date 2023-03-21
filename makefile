CC=g++
CFLAGS=-Wall -std=c++17
LDFLAGS=-lGLEW -lGL -lGLU -lglfw -lm
INCLUDES=-I/usr/include/GL -I/usr/include

SOURCES=src/*.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=program

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
