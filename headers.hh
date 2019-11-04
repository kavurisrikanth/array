#include <iostream>
#include <cstdlib>
#include <cstring>

template <typename T>
class ResizableArray
{
    T *list;
    int capacity; // Declared size
    int size;     // Number of items

public:
    ResizableArray(int capacity) : capacity(capacity), size(0)
    {
        this->list = (T *)calloc(1, capacity * sizeof(T));
    }

    void put(T data)
    {
        list[size++] = data;
    }

    T get(int index)
    {
        if (size == 0)
        {
            throw "List is empty.";
        }

        if (size <= index)
        {
            throw "Index out of bounds!";
        }

        return list[index];
    }

    T remove(int index)
    {
        T current = get(index);
        --size;
        return current;
    }

    int getSize()
    {
        return size;
    }

    ~ResizableArray()
    {
        free(this->list);
        this->list = NULL;
        this->capacity = 0;
        this->size = 0;
    }
};