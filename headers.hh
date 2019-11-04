#include <iostream>
#include <cstdlib>
#include <cstring>

template <typename T>
class Array {
    T *list;
    int size;       // Number of items
    int capacity;   // Declared size

    public:
        Array(int capacity) : capacity(capacity) {}
};