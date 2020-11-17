#if !defined(INCLUDED_CORE_STANDARD_TYPE)
#define INCLUDED_CORE_STANDARD_TYPE

#include <core/trait/condition.hpp>

namespace universe::core {
    using uint1 = unsigned char;
    using uint2 = condition<sizeof(int) == 2, unsigned int, unsigned short>;
    using uint4 = condition<sizeof(long) == 4, unsigned long, unsigned int>;
    using uint8 = condition<sizeof(long) == 8, unsigned long, unsigned long long>;

    using sint1 = signed char;
    using sint2 = condition<sizeof(int) == 2, signed int, signed short>;
    using sint4 = condition<sizeof(long) == 4, signed long, signed int>;
    using sint8 = condition<sizeof(long) == 8, signed long, signed long long>;

    using real4 = float;
    using real8 = double;
    using real10 = condition<(sizeof(long double) > sizeof(double)), long double, double>;

    #if defined(CORE_USE_DOUBLE)
    using real = double;
    #else
    using real = float;
    #endif

    using size = decltype(sizeof(0));
    using byte = uint1;
    using ptrdiff = decltype(static_cast<byte*>(0) - static_cast<byte*>(0));
}

#endif