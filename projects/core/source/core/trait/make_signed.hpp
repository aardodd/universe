#if !defined(INCLUDED_CORE_TRAIT_MAKE_SIGNED)
#define INCLUDED_CORE_TRAIT_MAKE_SIGNED

#include <core/standard/type.hpp>
#include <core/trait/type_identity.hpp>

namespace universe::core {
    namespace detail {
        template<unsigned long long N>
        struct make_signed_helper : type_identity<void>{};

        template<>
        struct make_signed_helper<1> : type_identity<sint1>{};

        template<>
        struct make_signed_helper<2> : type_identity<sint2>{};

        template<>
        struct make_signed_helper<4> : type_identity<sint4>{};

        template<>
        struct make_signed_helper<8> : type_identity<sint8>{};
    }

    template<typename T>
    using make_signed = typename detail::make_signed_helper<sizeof(T)>::value;
}

#endif