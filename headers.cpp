// Just added to help the makefile properly generate object files

#include "headers.hh"
#include <cassert>
#include <iostream>

void test();
void testPushAndPop();
void testPopOnEmptyList();

int main(void) {
    test();
    return 0;
}

void test() {
    testPushAndPop();
    testPopOnEmptyList();
}

void testPopOnEmptyList() {
    ResizableArray<int> arr(10);
    assert(arr.getSize() == 0);
    try {
        arr.pop();
    } catch (IndexOutOfBoundsException e) {
        assert(strcmp(e.what(), "Index out of bounds: -1") == 0);
    } catch (UnderflowException e) {
        assert(strcmp(e.what(), "List is empty.") == 0);
    }
}

void testPushAndPop() {
    ResizableArray<int> arr(10);

    int i;
    for (i = 0; i < 7; i++) {
        assert(arr.getSize() == i);
        arr.put(i);
    }
    assert(arr.getSize() == 7);

    i--;
    while (!arr.empty()) {
        assert(arr.pop() == i--);
    }
}