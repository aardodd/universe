#if !defined(INCLUDED_CORE_TRAIT_TYPE_IDENTITY)
#define INCLUDED_CORE_TRAIT_TYPE_IDENTITY

namespace universe::core {
    template<typename T>
    struct type_identity{ using value = T; };
}

#endif