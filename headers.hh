#include <cstdlib>
#include <cstring>

#include "IndexOutOfBoundsException.hh"
#include "UnderflowException.hh"

template <typename T>
class ResizableArray {
    T *list;       // The array
    int capacity;  // Declared size
    int size;      // Number of items

    // Shrink test
    bool canShrink() { return (float)size / capacity <= 0.3; }

    // Expand test
    bool mustExpand() { return (float)size / capacity >= 0.8; }

    // Shrink op
    void shrink() { move(capacity / 2); }

    // Expand op
    void expand() { move(capacity * 2); }

    // Create new list, populate new list, and replace existing list
    void move(int newCap) {
        T *newList = (T *)calloc(1, newCap * sizeof(T));
        memcpy(newList, list, size * sizeof(T));
        free(list);
        list = newList;
        capacity = newCap;
    }

   public:
    // Constructor
    ResizableArray(int capacity) : capacity(capacity), size(0) {
        this->list = (T *)calloc(1, capacity * sizeof(T));
    }

    // Insert
    void put(T data) {
        list[size++] = data;
        if (mustExpand()) {
            expand();
        }
    }

    // Get item at index
    T get(int index) {
        if (size == 0) {
            throw UnderflowException("List is empty.");
        }

        if (index < 0 || index >= size) {
            throw IndexOutOfBoundsException(index);
        }

        return list[index];
    }

    // Get item and remove it from list
    T remove(int index) {
        T current = get(index);
        --size;
        if (canShrink()) {
            shrink();
        }
        return current;
    }

    // Pop (like a stack)
    T pop() { return remove(size - 1); }

    // Size getter
    int getSize() { return size; }

    bool empty() { return size == 0; }

    // Destructor
    ~ResizableArray() {
        free(this->list);
        this->list = NULL;
        this->capacity = 0;
        this->size = 0;
    }
};