HEADERS = input-value.hpp bin.hpp online-bin-problem.hpp offline-bin-problem.hpp
TEST_SOURCES = ./tests/input-value-test.cpp ./tests/bin-test.cpp ./tests/online-bin-problem-test.cpp ./tests/offline-bin-problem-test.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
MAIN_SOURCES = main.cpp input-value.cpp bin.cpp online-bin-problem.cpp offline-bin-problem.cpp
MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)
TEST_TARGETS = $(TEST_SOURCES:.cpp=.out)
MAIN_TARGET = main_executable

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I.

.PHONY: all run-test main run-main clean

all: $(TEST_TARGETS) $(MAIN_TARGET)

$(TEST_TARGETS): %.out: %.o input-value.o bin.o online-bin-problem.o offline-bin-problem.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MAIN_TARGET): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run-test: $(TEST_TARGETS)
	for test in $(TEST_TARGETS); do ./$$test; done

run-main: $(MAIN_TARGET)
	./$(MAIN_TARGET)

clean:
	rm -f $(TEST_OBJECTS) $(TEST_TARGETS) $(MAIN_OBJECTS) $(MAIN_TARGET)