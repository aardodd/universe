#if !defined(INCLUDED_CORE_MATH_VECTOR2)
#define INCLUDED_CORE_MATH_VECTOR2

#include <core/math/sqrt.hpp>
#include <core/standard/assert.hpp>
#include <core/standard/type.hpp>

namespace universe::core {
    template<typename T>
    struct vector2 {
        constexpr inline vector2() : x(0), y(0) {};
        constexpr inline vector2(const T& _x, const T& _y) : x(_x), y(_y) {};
        constexpr inline vector2(const T (&_values)[2]) : x(_values[0]), y(_values[1]) {};

        // member functions
        constexpr inline T length_squared() const;
        constexpr inline T length() const;

        // operators
        constexpr inline void operator+=(const vector2<T>& _a);
        constexpr inline void operator-=(const vector2<T>& _a);
        constexpr inline void operator*=(const vector2<T>& _a);
        constexpr inline void operator/=(const vector2<T>& _a);

        constexpr inline void operator+=(const T& _a);
        constexpr inline void operator-=(const T& _a);
        constexpr inline void operator*=(const T& _a);
        constexpr inline void operator/=(const T& _a);

        constexpr inline T& operator[](const size& _index) {
            CORE_RUNTIME_ASSERT(_index >= 0 && _index < 2, "_index out of range");
            return array[_index];
        }

        constexpr inline const T& operator[](const size& _index) const {
            CORE_RUNTIME_ASSERT(_index >= 0 && _index < 2, "_index out of range");
            return array[_index];
        }

        // data
        union {
            struct { T u, v; };
            struct { T s, t; };
            struct { T x, y; };
            struct { T w, h; };
            T array[2];
        };
    };

    using vector2r = vector2<real>;
    using vector2b = vector2<bool>;
    using vector2z = vector2<size>;

    //
    // member functions
    //
    template<typename T>
    constexpr inline T vector2<T>::length_squared() const {
        return x * x + y * y;
    }

    template<typename T>
    constexpr inline T vector2<T>::length() const {
        return sqrt(length_squared());
    }

    template<typename T>
    constexpr inline vector2<T> normalize(const vector2<T> &_a) {
        return { _a / _a.length() };
    }

    //
    // logical Operators
    //
    template<typename T>
    constexpr inline bool operator==(const vector2<T>& _lhs, const vector2<T>& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y;
    }

    template<typename T>
    constexpr inline bool operator!=(const vector2<T>& _lhs, const vector2<T>& _rhs) {
        return _lhs.x != _rhs.x || _lhs.y != _rhs.y;
    }

    //
    // unary Operators
    //
    template<typename T>
    constexpr inline vector2<T> operator+(const vector2<T>& _a) {
        return { +_a.x, +_a.y };
    }

    template<typename T>
    constexpr inline vector2<T> operator-(const vector2<T>& _a) {
        return { -_a.x, -_a.y };
    }

    //
    // vector assignment operators
    //
    template<typename T>
    constexpr inline void vector2<T>::operator+=(const vector2<T>& _a) {
        x += _a.x;
        y += _a.y;
    }

    template<typename T>
    constexpr inline void vector2<T>::operator-=(const vector2<T>& _a) {
        x -= _a.x;
        y -= _a.y;
    }

    template<typename T>
    constexpr inline void vector2<T>::operator*=(const vector2<T>& _a) {
        x *= _a.x;
        y *= _a.y;
    }

    template<typename T>
    constexpr inline void vector2<T>::operator/=(const vector2<T>& _a) {
        x /= _a.x;
        y /= _a.y;
    }

    //
    // vector binary operators
    //
    template<typename T>
    constexpr inline vector2<T> operator+(const vector2<T>& _a, const vector2<T>& _b) {
        return {_a.x + _b.x, _a.y + _b.y };
    }

    template<typename T>
    constexpr inline vector2<T> operator-(const vector2<T>& _a, const vector2<T>& _b) {
        return {_a.x - _b.x, _a.y - _b.y };
    }

    template<typename T>
    constexpr inline vector2<T> operator*(const vector2<T>& _a, const vector2<T>& _b) {
        return {_a.x * _b.x, _a.y * _b.y };
    }

    template<typename T>
    constexpr inline vector2<T> operator/(const vector2<T>& _a, const vector2<T>& _b) {
        return {_a.x / _b.x, _a.y / _b.y };
    }

    //
    // scalar assignment operators
    //
    template<typename T>
    constexpr inline void vector2<T>::operator+=(const T& _a) {
        x += _a;
        y += _a;
    }

    template<typename T>
    constexpr inline void vector2<T>::operator-=(const T& _a) {
        x -= _a;
        y -= _a;
    }

    template<typename T>
    constexpr inline void vector2<T>::operator*=(const T& _a) {
        x *= _a;
        y *= _a;
    }

    template<typename T>
    constexpr inline void vector2<T>::operator/=(const T& _a) {
        x /= _a;
        y /= _a;
    }

    //
    // scalar binary operators
    //
    template<typename T>
    constexpr inline vector2<T> operator+(const vector2<T>& _a, const T& _b) {
        return {_a.x + _b, _a.y + _b };
    }

    template<typename T>
    constexpr inline vector2<T> operator-(const vector2<T>& _a, const T& _b) {
        return {_a.x - _b, _a.y - _b };
    }

    template<typename T>
    constexpr inline vector2<T> operator*(const vector2<T>& _a, const T& _b) {
        return {_a.x * _b, _a.y * _b };
    }

    template<typename T>
    constexpr inline vector2<T> operator/(const vector2<T>& _a, const T& _b) {
        return {_a.x / _b, _a.y / _b };
    }

    template<typename T>
    constexpr inline vector2<T> operator+(const T& _a, const vector2<T>& _b) {
        return _b + _a;
    }

    template<typename T>
    constexpr inline vector2<T> operator-(const T& _a, const vector2<T>& _b) {
        return _b - _a;
    }

    template<typename T>
    constexpr inline vector2<T> operator*(const T& _a, const vector2<T>& _b) {
        return _b * _a;
    }

    template<typename T>
    constexpr inline vector2<T> operator/(const T& _a, const vector2<T>& _b) {
        return _b / _a;
    }
}

#endif