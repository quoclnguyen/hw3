CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test.o: llrec-test.cpp llrec.cpp llrec.h 
	$(CXX) $(CXXFLAGS) $^ -o $@ llrec-test.cpp

stack-test.o: stack-test.cpp stack.h
	$(CXX) $(CXXFLAGS) $^ -o $@ stack-test.cpp



clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 