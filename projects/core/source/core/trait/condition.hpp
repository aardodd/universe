#if !defined(INCLUDED_CORE_TRAIT_CONDITION)
#define INCLUDED_CORE_TRAIT_CONDITION

#include <core/trait/type_identity.hpp>

namespace universe::core {
    namespace detail {
        template<bool B, typename T, typename F>
        struct condition : type_identity<T> {};

        template<typename T, typename F>
        struct condition<false, T, F> : type_identity<F> {};
    }

    template<bool B, typename T, typename F>
    using condition = typename detail::condition<B, T, F>::value;
}

#endif