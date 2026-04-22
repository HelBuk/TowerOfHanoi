CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

all: hanoi

hanoi: main.cpp hanoi.cpp hanoi.hpp
	$(CXX) $(CXXFLAGS) main.cpp hanoi.cpp -o hanoi

tests: tests.cpp hanoi.cpp hanoi.hpp
	$(CXX) $(CXXFLAGS) tests.cpp hanoi.cpp -o tests

test: tests
	./tests

clean:
	rm -f hanoi tests *.o