#if !defined(INCLUDED_CORE_TRAIT_IS_RATIONAL)
#define INCLUDED_CORE_TRAIT_IS_RATIONAL

#include <core/trait/is_same.hpp>

namespace universe::core {
    template<typename T>
    constexpr inline bool is_rational{
        is_same<T, float> ||
        is_same<T, double> ||
        is_same<T, long double>
    };
}

#endif