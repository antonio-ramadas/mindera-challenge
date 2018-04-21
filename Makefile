CXX=g++
RM=del /Q
CXXFLAGS=-std=c++14 -Wall

SRCS=src/main.cpp src/Printer.cpp src/Parser.cpp src/Algorithm.cpp src/FloodFill.cpp src/SmartFill.cpp
TARGET=build/main
OBJS=build\*

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	$(RM) $(OBJS)
