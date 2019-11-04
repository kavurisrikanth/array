CXX = g++
CXXFLAGS = -Wall -g -std=c++17

array: headers.o
	$(CXX) $(CXXFLAGS) -o array headers.o

headers.o: headers.hh

clean:
	rm array *.o *.gch