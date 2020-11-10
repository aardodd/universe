#include <core/standard/assert.hpp>
#include <iostream>

namespace universe::core {
    void __core_runtime_assert(const char *message, const char *file, int line) {
        std::cout << file << ':' << line << ": " << message << '\n';
    }
}