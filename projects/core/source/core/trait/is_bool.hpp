#if !defined(INCLUDED_CORE_TRAIT_IS_BOOL)
#define INCLUDED_CORE_TRAIT_IS_INTEGRAL

#include <core/trait/is_same.hpp>

namespace universe::core {
    template<typename T>
    constexpr inline bool is_bool{
        is_same<T, bool>
    };
}

#endif