#if !defined(INCLUDED_CORE_FRAMEWORK_OBSERVER)
#define INCLUDED_CORE_FRAMEWORK_OBSERVER

#include <core/container/array.hpp>
#include <core/standard/type.hpp>

namespace universe::core {
    template<typename T, size N>
    struct observable {
        private:
            struct observer_item {
                constexpr inline observer_item(T &_observer) : m_observer(&_observer), m_enabled(true) {};

                T *m_observer;
                bool m_enabled;
            };

            struct observer_compare {
                constexpr inline observer_compare(T& _observer) : m_observer(&_observer) {};

                constexpr inline bool operator()(const observer_item& _item) const {
                    return m_observer == _item.m_observer;
                }

                T *m_observer;
            };


        
        public:


        private:
        array<observer_item[N]> m_observer_list;
    };

    template<typename T, typename... Ts>
    struct observer : observer<T>, observer<Ts...> {
        using observer<T>::accept;
        using observer<Ts...>::accept;
    };

    template<typename T>
    struct observer<T> {
        virtual ~observer() {}
        virtual void notification(T) = 0;
    };
}

#endif