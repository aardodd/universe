#if !defined(INCLUDED_CORE_TRAIT_IS_SIGNED)
#define INCLUDED_CORE_TRAIT_IS_SIGNED

#include <core/trait/is_same.hpp>

namespace universe::core {
    template<typename T>
    constexpr inline bool is_signed{
        is_same<T, signed char> ||
        is_same<T, signed short> ||
        is_same<T, signed int> ||
        is_same<T, signed long> ||
        is_same<T, signed long long>
    };
}

#endif