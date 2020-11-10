#if !defined(INCLUDED_CORE_UTILITY_MEMORY_COPY)
#define INCLUDED_CORE_UTILITY_MEMORY_COPY

#include <core/standard/type.hpp>

namespace universe::core {
    void memory_copy(void *_destination, void *_source, size _size);
}

#endif