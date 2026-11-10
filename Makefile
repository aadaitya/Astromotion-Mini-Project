CC=gcc
CXX=g++
CFLAGS=-std=c11 -Wall -Wextra -Wpedantic -Iinclude
CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Iinclude
LDLIBS=-lm
GTEST=-lgtest -lgtest_main -pthread
SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c,build/%.o,$(SRC))
TESTS=$(wildcard tests/*.cpp)
.PHONY: all run test clean
all: build/astromotion
build:
	mkdir -p build
build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@
build/astromotion: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)
build/tests: $(filter-out build/main.o,$(OBJ)) $(TESTS) | build
	$(CXX) $(CXXFLAGS) $(TESTS) $(filter-out build/main.o,$(OBJ)) -o $@ $(GTEST) $(LDLIBS)
run: all
	./build/astromotion
test: build/tests
	./build/tests
clean:
	rm -rf build
