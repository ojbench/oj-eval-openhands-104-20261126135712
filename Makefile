CXX = g++
CXXFLAGS = -O2 -std=c++17

all: code

code: solution.cpp
	$(CXX) $(CXXFLAGS) -o code solution.cpp

clean:
	rm -f code

.PHONY: all clean
