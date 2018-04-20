CXX=g++
RM=del /Q
CXXFLAGS=-std=c++14 -Wall

SRCS=src/main.cpp
TARGET=build/main
OBJS=build\*

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	$(RM) $(OBJS)
