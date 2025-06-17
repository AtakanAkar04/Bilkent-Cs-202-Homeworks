CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -O2

# Default target
all: substrings minimalset lexicographic insertionorders

# Rules to build executables
substrings: substrings.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

minimalset: minimalset.cpp HashTable.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

lexicographic: lexicographic.cpp 
	$(CXX) $(CXXFLAGS) -o $@ $^

insertionorders: insertionorders.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean rule
clean:
	rm -f substrings minimalset lexicographic insertionorders

# Mark targets as phony
.PHONY: all clean
