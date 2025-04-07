# Email: peeruzia@gmail.com
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude
SRC = src/Graph.cpp src/Algorithms.cpp src/Queue.cpp src/PriorityQueue.cpp src/UnionFind.cpp
OBJ = $(SRC:.cpp=.o)

all: Main

Main: main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -o Main main.cpp $(OBJ)

test: test/test_graph.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -o test_runner test/test_graph.cpp $(OBJ)
	./test_runner

valgrind: Main
	valgrind --leak-check=full ./Main

clean:
	rm -f *.o src/*.o Main test_runner
