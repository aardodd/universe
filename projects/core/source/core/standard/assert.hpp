#if !defined(INCLUDED_CORE_STANDARD_ASSERT)
#define INCLUDED_CORE_STANDARD_ASSERT

namespace universe::core {
    template<bool B>
    struct CORE_ASSERT_FAILURE;

    template<>
    struct CORE_ASSERT_FAILURE<true> { enum { value = 1 }; };

    template<size_t N>
    struct CORE_ASSERT_TEST{};

    void __core_runtime_assert(const char *message, const char *file, int line); 
}

#define CORE_STATIC_ASSERT(cond, message) typedef universe::core::CORE_ASSERT_TEST<sizeof(universe::core::CORE_ASSERT_FAILURE<(bool)(cond)>)> __core_assert_typedef

#define CORE_RUNTIME_ASSERT(cond, message) do { if (!(cond)) { universe::core::__core_runtime_assert((message), __FILE__, __LINE__); } } while (0)

#endif