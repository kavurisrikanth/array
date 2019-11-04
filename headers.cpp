// Just added to help the makefile properly generate object files

#include "headers.hh"
#include <cassert>

int main(void) {
    ResizableArray<int> arr(10);
    for (int i = 0; i < 5; i++) {
        assert(arr.getSize() == i);
        arr.put(i);
    }
    return 0;
}