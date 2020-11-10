#if !defined(INCLUDED_CORE_MATH_RAY)
#define INCLUDED_CORE_MATH_RAY

#include <core/math/vector3.hpp>

namespace universe::core {
    template<typename T>
    struct ray {
        constexpr inline ray() : origin(0), direction(0) {};
        constexpr inline ray(const vector3<T>& _origin, const vector3<T>& _direction) : origin(_origin), direction(_direction) {};

        constexpr inline vector3<T> operator()(T _a) const {
            return origin + direction * _a;
        }

        vector3<T> origin;
        vector3<T> direction;
    };
}

#endif