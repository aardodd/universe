#if !defined(INCLUDED_CORE_MATH_SQRT)
#define INCLUDED_CORE_MATH_SQRT

#include <cmath>

namespace universe::core {
    template<typename T>
    constexpr inline T sqrt(T _value) {
        return std::sqrt(_value);
    }
}

#endif