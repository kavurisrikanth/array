#include <cstdio>
#include <cstring>
#include <exception>
#include <string>

class UnderflowException : std::exception {
    std::string msg;

   public:
    UnderflowException(std::string msg) : std::exception(), msg(msg) {}

    const char *what() const noexcept {
        return msg.c_str();
    }
};