#if !defined(INCLUDED_CORE_MATH_MIN)
#define INCLUDED_CORE_MATH_MIN

namespace universe::core {
    template<typename T>
    constexpr inline T min(const T& _lhs, const T& _rhs) {
        if (_lhs <= _rhs) {
            return _lhs;
        }

        return _rhs;
    }

    template<typename T, typename U>
    constexpr inline T min(const T& _lhs, const U& _rhs) {
        if (_lhs <= _rhs) {
            return _lhs;
        }

        return static_cast<T>(_rhs);
    }
}

#endif