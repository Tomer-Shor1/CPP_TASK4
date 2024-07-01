CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
TARGET = tree_program
TEST_TARGET = test_tree
SRCS = main.cpp
TEST_SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -lsfml-graphics -lsfml-window -lsfml-system

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

main.o: main.cpp tree.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test.o: test.cpp tree.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_TARGET) $(TEST_OBJS)

.PHONY: clean
