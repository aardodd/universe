#if !defined(INCLUDED_CORE_TRAIT_IS_SAME)
#define INCLUDED_CORE_TRAIT_IS_SAME

namespace universe::core {
    namespace detail {
        template<typename T1, typename T2>
        constexpr inline bool is_same{false};

        template<typename T>
        constexpr inline bool is_same<T, T>{true};
    }

    template<typename T1, typename T2>
    constexpr inline bool is_same = detail::is_same<T1, T2>;
}

#endif