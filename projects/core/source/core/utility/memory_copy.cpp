#include <core/utility/memory_copy.hpp>

namespace universe::core {
    void memory_copy(void *_destination, void *_source, size _size) {
        byte* db{static_cast<byte*>(_destination)};
        byte* sb{static_cast<byte*>(_source)};

        for (size i = 0; i < _size; i++) {
            db[i] = sb[i];
        }

        return;
    }
}