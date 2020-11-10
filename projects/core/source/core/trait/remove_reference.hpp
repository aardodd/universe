#if !defined(INCLUDED_CORE_TRAIT_REMOVE_REFERENCE)
#define INCLUDED_CORE_TRAIT_REMOVE_REFERENCE

#include <core/trait/type_identity.hpp>

namespace universe::core {
    namespace detail {
        template<typename T>
        struct remove_reference : type_identity<T> {};

        template<typename T>
        struct remove_reference<T&> : type_identity<T> {};

        template<typename T>
        struct remove_reference<T&&> : type_identity<T> {};
    }

    template<typename T>
    using remove_reference = typename detail::remove_reference<T>::value;
}

#endif