TARGET = GLTask
CC = gcc
CXX = g+
CFLAGS = -g -Wall
SOURCES = main.cpp IPAddress.cpp 
INCLUDES = IPAddress.h
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(TARGET) $(INCLUDES)

$(TARGET): $(OBJECTS) 
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@