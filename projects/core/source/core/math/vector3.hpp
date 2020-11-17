#if !defined(INCLUDED_CORE_MATH_VECTOR3)
#define INCLUDED_CORE_MATH_VECTOR3

#include <core/math/abs.hpp>
#include <core/math/sqrt.hpp>
#include <core/standard/assert.hpp>
#include <core/standard/type.hpp>

namespace universe::core {
    template<typename T>
    struct vector3 {
        constexpr inline vector3() : x(0), y(0) {};
        constexpr inline vector3(const T& _x, const T& _y, const T& _z) : x(_x), y(_y), z(_z) {};
        constexpr inline vector3(const T (&_values)[3]) : x(_values[0]), y(_values[1]), z(_values[2]) {};

        // member functions
        constexpr inline T length_squared() const;
        constexpr inline T length() const;
        constexpr inline T cross() const;

        // operators
        constexpr inline void operator+=(const vector3<T>& _a);
        constexpr inline void operator-=(const vector3<T>& _a);
        constexpr inline void operator*=(const vector3<T>& _a);
        constexpr inline void operator/=(const vector3<T>& _a);

        constexpr inline void operator+=(const T& _a);
        constexpr inline void operator-=(const T& _a);
        constexpr inline void operator*=(const T& _a);
        constexpr inline void operator/=(const T& _a);

        constexpr inline T& operator[](const size& _index) {
            CORE_RUNTIME_ASSERT(_index >= 0 && _index <= 3, "_index out of range");
            return array[_index];
        }

        constexpr inline const T& operator[](const size& _index) const {
            CORE_RUNTIME_ASSERT(_index >= 0 && _index <= 3, "_index out of range");
            return array[_index];
        }

        // data
        union {
            struct { T r, g, b; };
            struct { T x, y, z; };
            struct { T w, h, d; };
            T array[3];
        };
    };

    using vector3r = vector3<real>;
    using vector3b = vector3<bool>;
    using vector3z = vector3<size>;

    //
    // member functions
    //
    template<typename T>
    constexpr inline T vector3<T>::length_squared() const {
        return x * x + y * y + z * z;
    }

    template<typename T>
    constexpr inline T vector3<T>::length() const {
        return sqrt(length_squared());
    }

    template<typename T>
    constexpr inline T dot(const vector3<T> &_a, const vector3<T> &_b) {
        return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z;
    }

    template<typename T>
    constexpr inline T abs_dot(const vector3<T> &_a, const vector3<T> &_b) {
        return abs(dot(_a, _b));
    }

    template<typename T>
    constexpr inline vector3<T> cross(const vector3<T> &_a, const vector3<T> &_b) {
        return {
            (_a.y * _b.z) - (_a.z * _b.y),
            (_a.z * _b.x) - (_a.x * _b.z),
            (_a.x * _b.y) - (_a.y * _b.x)
        };
    }

    template<typename T>
    constexpr inline vector3<T> normalize(const vector3<T> &_a) {
        return { _a / _a.length() };
    }

    //
    // logical Operators
    //
    template<typename T>
    constexpr inline bool operator==(const vector3<T>& _lhs, const vector3<T>& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z;
    }

    template<typename T>
    constexpr inline bool operator!=(const vector3<T>& _lhs, const vector3<T>& _rhs) {
        return _lhs.x != _rhs.x || _lhs.y != _rhs.y || _lhs.z != _rhs.z;
    }

    //
    // unary Operators
    //
    template<typename T>
    constexpr inline vector3<T> operator+(const vector3<T>& _a) {
        return { +_a.x, +_a.y, +_a.z };
    }

    template<typename T>
    constexpr inline vector3<T> operator-(const vector3<T>& _a) {
        return { -_a.x, -_a.y, -_a.z };
    }

    //
    // vector assignment operators
    //
    template<typename T>
    constexpr inline void vector3<T>::operator+=(const vector3<T>& _a) {
        x += _a.x;
        y += _a.y;
        z += _a.z;
    }

    template<typename T>
    constexpr inline void vector3<T>::operator-=(const vector3<T>& _a) {
        x -= _a.x;
        y -= _a.y;
        z -= _a.z;
    }

    template<typename T>
    constexpr inline void vector3<T>::operator*=(const vector3<T>& _a) {
        x *= _a.x;
        y *= _a.y;
        z *= _a.z;
    }

    template<typename T>
    constexpr inline void vector3<T>::operator/=(const vector3<T>& _a) {
        x /= _a.x;
        y /= _a.y;
        z /= _a.z;
    }

    //
    // vector binary operators
    //
    template<typename T>
    constexpr inline vector3<T> operator+(const vector3<T>& _a, const vector3<T>& _b) {
        return {_a.x + _b.x, _a.y + _b.y, _a.z + _b.z };
    }

    template<typename T>
    constexpr inline vector3<T> operator-(const vector3<T>& _a, const vector3<T>& _b) {
        return {_a.x - _b.x, _a.y - _b.y, _a.z - _b.z };
    }

    template<typename T>
    constexpr inline vector3<T> operator*(const vector3<T>& _a, const vector3<T>& _b) {
        return {_a.x * _b.x, _a.y * _b.y, _a.z * _b.z };
    }

    template<typename T>
    constexpr inline vector3<T> operator/(const vector3<T>& _a, const vector3<T>& _b) {
        return {_a.x / _b.x, _a.y / _b.y, _a.z / _b.z };
    }

    //
    // scalar assignment operators
    //
    template<typename T>
    constexpr inline void vector3<T>::operator+=(const T& _a) {
        x += _a;
        y += _a;
        z += _a;
    }

    template<typename T>
    constexpr inline void vector3<T>::operator-=(const T& _a) {
        x -= _a;
        y -= _a;
        y -= _a;
    }

    template<typename T>
    constexpr inline void vector3<T>::operator*=(const T& _a) {
        x *= _a;
        y *= _a;
        y *= _a;
    }

    template<typename T>
    constexpr inline void vector3<T>::operator/=(const T& _a) {
        x /= _a;
        y /= _a;
        z /= _a;
    }

    //
    // scalar binary operators
    //
    template<typename T>
    constexpr inline vector3<T> operator+(const vector3<T>& _a, const T& _b) {
        return {_a.x + _b, _a.y + _b, _a.z + _b };
    }

    template<typename T, typename U>
    constexpr inline vector3<T> operator+(const vector3<T>& _a, const U& _b) {
        return {_a.x + static_cast<T>(_b), _a.y + static_cast<T>(_b), _a.z + static_cast<T>(_b) };
    }

    template<typename T>
    constexpr inline vector3<T> operator-(const vector3<T>& _a, const T& _b) {
        return {_a.x - _b, _a.y - _b, _a.z - _b };
    }

    template<typename T, typename U>
    constexpr inline vector3<T> operator-(const vector3<T>& _a, const U& _b) {
        return {_a.x - static_cast<T>(_b), _a.y - static_cast<T>(_b), _a.z - static_cast<T>(_b) };
    }

    template<typename T>
    constexpr inline vector3<T> operator*(const vector3<T>& _a, const T& _b) {
        return {_a.x * _b, _a.y * _b, _a.z * _b };
    }

    template<typename T, typename U>
    constexpr inline vector3<T> operator*(const vector3<T>& _a, const U& _b) {
        return {_a.x / static_cast<T>(_b), _a.y / static_cast<T>(_b), _a.z / static_cast<T>(_b) };
    }

    template<typename T>
    constexpr inline vector3<T> operator/(const vector3<T>& _a, const T& _b) {
        return {_a.x / _b, _a.y / _b, _a.z / _b };
    }

    template<typename T, typename U>
    constexpr inline vector3<T> operator/(const vector3<T>& _a, const U& _b) {
        return {_a.x / static_cast<T>(_b), _a.y / static_cast<T>(_b), _a.z / static_cast<T>(_b) };
    }

    template<typename T>
    constexpr inline vector3<T> operator+(const T& _a, const vector3<T>& _b) {
        return _b + _a;
    }

    template<typename T, typename U>
    constexpr inline vector3<T> operator+(const U& _a, const vector3<T>& _b) {
        return _b + _a;
    }

    template<typename T>
    constexpr inline vector3<T> operator-(const T& _a, const vector3<T>& _b) {
        return _b - _a;
    }

    template<typename T, typename U>
    constexpr inline vector3<T> operator-(const U& _a, const vector3<T>& _b) {
        return _b - _a;
    }

    template<typename T>
    constexpr inline vector3<T> operator*(const T& _a, const vector3<T>& _b) {
        return _b * _a;
    }

    template<typename T, typename U>
    constexpr inline vector3<T> operator*(const U& _a, const vector3<T>& _b) {
        return _b * _a;
    }

    template<typename T>
    constexpr inline vector3<T> operator/(const T& _a, const vector3<T>& _b) {
        return _b / _a;
    }

    template<typename T, typename U>
    constexpr inline vector3<T> operator/(const U& _a, const vector3<T>& _b) {
        return _b / _a;
    }
}

#endif