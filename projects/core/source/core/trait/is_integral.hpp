#if !defined(INCLUDED_CORE_TRAIT_IS_INTEGRAL)
#define INCLUDED_CORE_TRAIT_IS_INTEGRAL

#include <core/trait/is_signed.hpp>
#include <core/trait/is_unsigned.hpp>

namespace universe::core {
    template<typename T>
    constexpr inline bool is_integral{
        is_signed<T> || is_unsigned<T>
    };
}

#endif