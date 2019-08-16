CXX = clang++
CXXFLAGS = $(evaluator) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpthread -lm

all : test
Evaluate.o : Evaluate.cpp Evaluate.h
		$(CXX) $(CXXFLAGS) Evaluate.cpp

test : tests.o Evaluate.o
		$(LD) tests.o Evaluate.o $(LDFLAGS) -o test

tests.o : tests/tests.cpp tests/catch.hpp Evaluate.h 
		$(CXX) $(CXXFLAGS) tests/tests.cpp

clean :
		rm -rf *.o