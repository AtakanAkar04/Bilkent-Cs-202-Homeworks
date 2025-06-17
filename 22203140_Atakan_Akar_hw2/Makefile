CXX = g++
CXXFLAGS = -Wall -g


TARGET = subarray  
GAME_TARGET = game  
PREFIX_TARGET = prefixsubarray  
LEAST5_TARGET = least5  

SRCS = subarray.cpp maxHeap.cpp Heap.cpp
GAME_SRCS = game.cpp BST.cpp maxHeap.cpp TreeNode.cpp Heap.cpp
PREFIX_SRCS = prefixsubarray.cpp maxHeap.cpp Heap.cpp
LEAST5_SRCS = least5.cpp maxHeap.cpp Heap.cpp

OBJS = $(SRCS:.cpp=.o)
GAME_OBJS = $(GAME_SRCS:.cpp=.o)
PREFIX_OBJS = $(PREFIX_SRCS:.cpp=.o)
LEAST5_OBJS = $(LEAST5_SRCS:.cpp=.o)

all: $(TARGET) $(GAME_TARGET) $(PREFIX_TARGET) $(LEAST5_TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(GAME_TARGET): $(GAME_OBJS)
	$(CXX) $(CXXFLAGS) -o $(GAME_TARGET) $(GAME_OBJS)

$(PREFIX_TARGET): $(PREFIX_OBJS)
	$(CXX) $(CXXFLAGS) -o $(PREFIX_TARGET) $(PREFIX_OBJS)

$(LEAST5_TARGET): $(LEAST5_OBJS)
	$(CXX) $(CXXFLAGS) -o $(LEAST5_TARGET) $(LEAST5_OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(GAME_OBJS) $(PREFIX_OBJS) $(LEAST5_OBJS) $(TARGET) $(GAME_TARGET) $(PREFIX_TARGET) $(LEAST5_TARGET)

.PHONY: all clean
