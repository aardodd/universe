#if !defined(INCLUDED_CORE_UTILITY_SWAP)
#define INCLUDED_CORE_UTILITY_SWAP

namespace universe::core {
    template<typename T>
    constexpr inline void swap(T& _lhs, T& _rhs) {
        T& other{_lhs};
        _lhs = _rhs;
        _rhs = other;
    }
}

#endif