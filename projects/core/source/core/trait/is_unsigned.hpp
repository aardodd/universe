#if !defined(INCLUDED_CORE_TRAIT_IS_UNSIGNED)
#define INCLUDED_CORE_TRAIT_IS_UNSIGNED

#include <core/trait/is_same.hpp>

namespace universe::core {
    template<typename T>
    constexpr inline bool is_unsigned{
        is_same<T, unsigned char> ||
        is_same<T, unsigned short> ||
        is_same<T, unsigned int> ||
        is_same<T, unsigned long> ||
        is_same<T, unsigned long long>
    };
}

#endif