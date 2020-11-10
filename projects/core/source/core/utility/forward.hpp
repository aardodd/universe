#if !defined(INCLUDED_CORE_UTILITY_FORWARD)
#define INCLUDED_CORE_UTILITY_FORWARD

#include <core/trait/remove_reference.hpp>

namespace universe::core {
    template <typename T>
    constexpr inline T&& forward(remove_reference<T>& _value) {
        return static_cast<T&&>(_value);
    }

    template <typename T>
    constexpr inline T&& forward(remove_reference<T>&& _value) {
        return static_cast<T&&>(_value);
    }
}

#endif