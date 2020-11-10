#if !defined(INCLUDED_CORE_UTILITY_EXCHANGE)
#define INCLUDED_CORE_UTILITY_EXCHANGE

#include <core/utility/forward.hpp>
#include <core/utility/move.hpp>

namespace universe::core {
    template<class T, class U = T>
    constexpr T exchange(T& _object, U&& _value) {
        T old_value = move(_object);
        _object = forward<U>(_value);
        return old_value;
    }
}

#endif