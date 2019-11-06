CXX = g++
CXXFLAGS = -Wall -g -std=c++17

array: headers.o IndexOutOfBoundsException.o
	$(CXX) $(CXXFLAGS) -o array headers.o IndexOutOfBoundsException.o

headers.o: headers.hh

clean:
	rm array *.o *.gch *.stackdump