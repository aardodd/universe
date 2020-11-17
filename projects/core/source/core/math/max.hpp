#if !defined(INCLUDED_CORE_MATH_MAX)
#define INCLUDED_CORE_MATH_MAX

namespace universe::core {
    template<typename T>
    constexpr inline T max(const T& _lhs, const T& _rhs) {
        if (_lhs >= _rhs) {
            return _lhs;
        }

        return _rhs;
    }

    template<typename T, typename U>
    constexpr inline T max(const T& _lhs, const U& _rhs) {
        if (_lhs >= _rhs) {
            return _lhs;
        }

        return static_cast<T>(_rhs);
    }
}

#endif