////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

/* 
    This is the template IMPLEMENTATION of the size1 code.  Include this
    *IF* you need the operator and it's not yet available as explicit 
    template instantiation.  
*/

#include <math/Size1.hpp>
#include <basic/Stream.hpp>
#include <basic/Logging.hpp>


namespace yq {

    template <typename T>
    constexpr Size1<T> Size1<T>::operator+() const noexcept
    {
        return *this;
    }

    template <typename T>
    constexpr Size1<T> Size1<T>::operator-() const noexcept
    {
        return Size1(-x);
    }
    
    template <typename T>
    constexpr Size1<T> Size1<T>::operator+(const Size1&b) const noexcept
    {
        return Size1(x+b.x);
    }

    template <typename T>
    Size1<T>& Size1<T>::operator+=(const Size1&b) noexcept
    {
        x += b.x;
        return *this;
    }

    template <typename T>
    constexpr Size1<T> Size1<T>::operator-(const Size1&b) const noexcept
    {
        return Size1(x-b.x);
    }

    template <typename T>
    Size1<T>& Size1<T>::operator-=(const Size1&b) noexcept
    {
        x -= b.x;
        return *this;
    }
    
    template <typename T>
    template <typename U>
    requires is_arithmetic_v<U>
    constexpr Size1<product_t<T,U>> Size1<T>::operator*(U b) const noexcept
    {
        return Size1<product_t<T,U>>( x*b );
    }
    
    template <typename T>
    template <typename U>
    requires (is_arithmetic_v<U> && self_mul_v<T,U>)
    Size1<T>& Size1<T>::operator*=(U b) noexcept
    {
        x *= b;
        return *this;
    }
    
    template <typename T>
    template <typename U>
    requires is_arithmetic_v<U>
    constexpr Size1<quotient_t<T,U>> Size1<T>::operator/(U b) const noexcept
    {
        return Size1<quotient_t<T,U>>( x/b );
    }
    
    template <typename T>
    template <typename U>
    requires (is_arithmetic_v<U> && self_div_v<T,U>)
    Size1<T>& Size1<T>::operator/=(U b) noexcept
    {
        x /= b;
        return *this;
    }

    template <typename T>
    constexpr bool  Size1<T>::contains(const Size1& b) const noexcept
    {
        return (x >= b.x);
    }
    
    template <typename T>
    constexpr T         Size1<T>::length() const noexcept 
    { 
        return x; 
    }

    template <typename T>
    constexpr T         Size1<T>::width() const 
    { 
        return x; 
    }

    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    template <typename S, typename T>
    S&  as_stream(S& s, const Size1<T>& v)
    {
        return s << "[" << v.x << "]";
    }
    
    /*! \brief Streams to a stream
    */
    template <typename T>
    Stream& operator<<(Stream&s, const Size1<T>& v)
    {
        return as_stream(s, v);
    }

    /*! \brief Streams to to a logging stream
    */
    template <typename T>
    log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream& s, const Size1<T>& v)
    {
        return as_stream(s, v);
    }
}
