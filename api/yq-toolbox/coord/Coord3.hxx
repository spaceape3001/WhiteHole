////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/coord/Coord3.hpp>
#include <yq-toolbox/coord/Coord.hpp>

namespace yq {
    template <typename T>
    constexpr Coord3<T> Coord3<T>::operator+() const noexcept
    {
        return *this;
    }
    
    template <typename T>
    constexpr Coord3<T> Coord3<T>::operator-() const noexcept
    {
        return { -i, -j, -k };
    }

    template <typename T>
    constexpr Coord3<T> Coord3<T>::operator+(const Coord3<T>&b) const noexcept
    {
        return { i+b.i, j+b.j, k+b.k };
    }

    template <typename T>
    constexpr Coord3<T> Coord3<T>::operator-(const Coord3<T>&b) const noexcept
    {
        return { i-b.i, j-b.j, k-b.k };
    }

    template <typename T>
    Coord3<T>& Coord3<T>::operator+=(const Coord3<T>& b) noexcept
    {
        i += b.i;
        j += b.j;
        k += b.k;
        return *this;
    }

    template <typename T>
    Coord3<T>& Coord3<T>::operator-=(const Coord3<T>& b) noexcept
    {
        i -= b.i;
        j -= b.j;
        k -= b.k;
        return *this;
    }

    template <typename T>
        template <typename U>
            requires is_arithmetic_v<U>
    constexpr Coord3<product_t<T,U>> Coord3<T>::operator*(U b) const noexcept
    {
        return { i*b, j*b, k*b };
    }

    template <typename T>
        template <typename U>
            requires (is_arithmetic_v<U> && self_multiply_v<T,U>)
    Coord3<T>& Coord3<T>::operator*=(U b) noexcept
    {
        i *= b;
        j *= b;
        k *= b;
        return *this;
    }

    template <typename T>
        template <typename U>
    constexpr Coord3<product_t<T,U>> Coord3<T>::operator*(const Coord3<U>& b) const noexcept
    {
        return { i*b.i, j*b.j, k*b.k };
    }
    
    template <typename T>
        template <typename U>
            requires self_multiply_v<T,U>
    Coord3<T>& Coord3<T>::operator*=(const Coord3<U>& b) noexcept
    {
        i *= b.i;
        j *= b.j;
        k *= b.k;
        return *this;
    }

    template <typename T>
        template <typename U>
            requires is_arithmetic_v<U>
    constexpr Coord3<quotient_t<T,U>> Coord3<T>::operator/(U b) const noexcept
    {
        return { i/b, j/b, k/b };
    }

    template <typename T>
        template <typename U>
            requires (is_arithmetic_v<U> && self_divide_v<T,U>)
    Coord3<T>& Coord3<T>::operator/=(U b) noexcept
    {
        i /= b;
        j /= b;
        k /= b;
        return *this;
    }

    template <typename T>
        template <typename U>
    constexpr Coord3<quotient_t<T,U>> Coord3<T>::operator/(const Coord3<U>& b) const noexcept
    {
        return { i/b.i, j/b.j, k/b.k };
    }

    template <typename T>
        template <typename U>
            requires self_divide_v<T,U>
    Coord3<T>& Coord3<T>::operator/=(const Coord3<U>& b) noexcept
    {
        i /= b.i;
        j /= b.j;
        k /= b.k;
        return *this;
    }

    template <typename T>
        template <typename S>
    S&  Coord3<T>::stream(S&s) const
    {
        return s << "[" << i << "," << j << "," << k << "]";
    }

    ////////////////////////////////////////////////////////////////////////////

    template <typename T, typename U>
        requires is_arithmetic_v<T>
    constexpr Coord3<product_t<T,U>> operator*(T a, const Coord3<U>&b)
    {
        return { a*b.i, a*b.j, a*b.k };
    }

    template <typename T>
    constexpr Coord3<T> max(const Coord3<T>&a, const Coord3<T>& b)
    {
        return { 
            max(a.i, b.i), 
            max(a.j, b.j), 
            max(a.k, b.k)
        };
    }

    template <typename T>
    constexpr Coord3<T> min(const Coord3<T>&a, const Coord3<T>& b)
    {
        return { 
            min(a.i, b.i), 
            min(a.j, b.j), 
            min(a.k, b.k)
        };
    }

    template <typename T>
    constexpr auto product(const Coord3<T>& a)
    {
        return a.i*a.j*a.k;
    }

    template <typename T>
    constexpr T sum(const Coord3<T>& a)
    {
        return a.i+a.j+a.k;
    }

    template <typename T>
    Stream& operator<<(Stream&s, const Coord3<T>& v)
    {
        return v.stream(s);
    }

    template <typename T>
    log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream& s, const Coord3<T>& v)
    {
        return v.stream(s);
    }
}