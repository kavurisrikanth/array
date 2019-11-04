// Just added to help the makefile properly generate object files

#include "headers.hh"
#include <cassert>

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
    } catch (const char* s) {
        assert(strcmp(s, "List is empty.") == 0);
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