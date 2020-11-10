#if !defined(INCLUDED_CORE_UTILITY_MOVE)
#define INCLUDED_CORE_UTILITY_MOVE

#include <core/trait/remove_reference.hpp>

namespace universe::core {
    template <typename T>
    constexpr inline remove_reference<T>&& move(T&& _value) noexcept {
        return static_cast<remove_reference<T>&&>(_value);
    }
}

#endif