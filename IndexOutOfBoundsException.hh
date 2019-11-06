#include <cstdio>
#include <cstring>
#include <exception>
#include <string>

class IndexOutOfBoundsException : std::exception {
    int index;

   public:
    IndexOutOfBoundsException(int index) : std::exception(), index(index) {}

    const char *what() const noexcept {
        return ("Index out of bounds: " + std::to_string(index)).c_str();
    }
};