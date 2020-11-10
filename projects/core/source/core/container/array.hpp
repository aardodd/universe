#if !defined(INCLUDED_CORE_CONTAINER_ARRAY)
#define INCLUDED_CORE_CONTAINER_ARRAY

#include <core/standard/type.hpp>
#include <core/utility/forward.hpp>

namespace universe::core {
    template<typename T>
    struct array;

    template<typename T, size N>
    struct array<T[N]> {
        template<typename... Ts>
        constexpr array(Ts&&... _arguments) : m_data{forward<Ts>(_arguments)...} {}

        constexpr inline T& operator[](size _index) {
            return m_data[_index];
        }

        constexpr inline const T& operator[](size _index) const {
            return m_data[_index];
        }

        private:
        T m_data[N];
    };

    // Deduction guide for Array{Ts...} to become Array<T[E]>.
    template<typename T, typename... Ts>
    array(T, Ts...) -> array<T[1 + sizeof...(Ts)]>;
}

#endif