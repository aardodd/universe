#if !defined(INCLUDED_CORE_FRAMEWORK_VISITOR)
#define INCLUDED_CORE_FRAMEWORK_VISITOR

namespace universe::core {
    template<typename T, typename... Ts>
    struct visitable : visitable<T>, visitable<Ts...> {
        using visitable<T>::accept;
        using visitable<Ts...>::accept;
    };

    template<typename T>
    struct visitable<T> {
        virtual ~visitable() {}
        virtual void accept(T&) = 0;
    };


    template<typename T, typename... Ts>
    struct visitor : visitor<T>, visitor<Ts...> {
        using visitor<T>::visit;
        using visitor<Ts...>::visit;
    };

    template<typename T>
    struct visitor<T> {
        virtual ~visitor() {}
        virtual void visit(T&) = 0;
    };
}

#endif