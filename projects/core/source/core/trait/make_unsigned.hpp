#if !defined(INCLUDED_CORE_TRAIT_MAKE_UNSIGNED)
#define INCLUDED_CORE_TRAIT_MAKE_UNSIGNED

#include <core/standard/type.hpp>
#include <core/trait/type_identity.hpp>

namespace universe::core {
    namespace detail {
        template<size N>
        struct make_unsigned_helper : type_identity<void>{};

        template<>
        struct make_unsigned_helper<1> : type_identity<uint1>{};

        template<>
        struct make_unsigned_helper<2> : type_identity<uint2>{};

        template<>
        struct make_unsigned_helper<4> : type_identity<uint4>{};

        template<>
        struct make_unsigned_helper<8> : type_identity<uint8>{};
    }

    template<typename T>
    using make_unsigned = detail::make_unsigned_helper<sizeof(T)>;
}

#endif