#if !defined(INCLUDED_CORE_MATH_ABS)
#define INCLUDED_CORE_MATH_ABS

namespace universe::core {
    template<typename T>
    constexpr inline T abs(const T& _value) {
        if (_value < 0) {
            return -_value;
        }

        return _value;
    }
}

#endif