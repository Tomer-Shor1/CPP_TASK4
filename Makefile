CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = tree_program
SRCS = main.cpp tree.cpp
OBJS = $(SRCS:.cpp=.o)
TEST_SRCS = test.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
TEST_TARGET = test

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(TEST_TARGET): $(TEST_OBJS) tree.o
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) tree.o

main.o: main.cpp tree.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

tree.o: tree.cpp tree.hpp
	$(CXX) $(CXXFLAGS) -c tree.cpp

test_tree.o: test_tree.cpp tree.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)
