////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

/* 
    This is the template IMPLEMENTATION of the sphere4 code.  Include this
    *IF* you need the operator and it's not yet available as explicit 
    template instantiation.  
*/

#include <math/AxBox4.hpp>
#include <math/Sphere4.hpp>

namespace yq {
    template <typename T>
    Sphere4<T>::Sphere4(focus_t, const Vector4<T>& focus, const Vector4<T>& edge) : 
        Sphere4(focus, (edge-focus).length()) {}

    template <typename T>
    Sphere4<T>::Sphere4(opposite_t, const Vector4<T>&a, const Vector4<T>&b) : 
        Sphere4(middivide(a,b), middivide((a-b).length())) {}

    template <typename T>
    constexpr Sphere4<T> Sphere4<T>::operator+() const noexcept
    {
        return Sphere4<T>(point, radius);
    }
    
    template <typename T>
    constexpr Sphere4<T> Sphere4<T>::operator-() const noexcept
    {
        return Sphere4<T>(-point, -radius);
    }

    template <typename T>
    constexpr Sphere4<T>   Sphere4<T>::operator+(const Vector4<T>&b) const noexcept
    {
        return Sphere4<T>(point+b, radius);
    }

    template <typename T>
    Sphere4<T>&            Sphere4<T>::operator+=(const Vector4<T>&b) noexcept
    {
        point += b;
        return *this;
    }

    template <typename T>
    constexpr Sphere4<T>   Sphere4<T>::operator-(const Vector4<T>&b) const noexcept
    {
        return Sphere4<T>(point-b,radius);
    }

    template <typename T>
    Sphere4<T>&            Sphere4<T>::operator-=(const Vector4<T>&b) noexcept
    {
        point -= b;
        return *this;
    }
    
    template <typename T>
        template <typename U>
    requires is_arithmetic_v<U>
    Sphere4<product_t<T,U>> Sphere4<T>::operator*(U b) const noexcept
    {
        return Sphere4<product_t<T,U>>( point*b, radius*positive(b));
    }
    
    template <typename T>
        template <typename U>
    requires (is_arithmetic_v<U> && self_mul_v<T,U>)
    Sphere4<T>& Sphere4<T>::operator*=(U b) noexcept
    {
        point  *= b;
        radius *= positive(b);
        return *this;
    }
        
    template <typename T>
        template <typename U>
    requires is_arithmetic_v<U>
    Sphere4<quotient_t<T,U>> Sphere4<T>::operator/(U b) const noexcept
    {
        return Sphere4<quotient_t<T,U>>( point/b, radius/positive(b));
    }
    
    template <typename T>
        template <typename U>
    requires (is_arithmetic_v<U> && self_div_v<T,U>)
    Sphere4<T>& Sphere4<T>::operator/=(U b) noexcept
    {
        point  /= b;
        radius /= positive(b);
        return *this;
    }


    template <typename T>
    constexpr AxBox4<T>   Sphere4<T>::bounds() const noexcept
    {
        T       r   = abs(radius);
        return { all(point) - r, all(point) + r };
    }

    template <typename T>
    constexpr T     Sphere4<T>::diameter() const noexcept
    {
        return radius + radius;
    }

    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    template <typename T, typename U>
    requires is_arithmetic_v<T>
    Sphere4<product_t<T,U>> operator*(T a, const Sphere4<U>& b)
    {
        return Sphere4<product_t<T,U>>(a*b.point, positive(a)*b.radius);
    }

    //! Returns the axially aligned box of a sphere
    template <typename T>
    AxBox4<T>   aabb(const Sphere4<T>& sph)
    {
        return sph.bounds();
    }

    /*! \brief Computes the diameter of a hyper sphere
    */
    template <typename T>
    constexpr T  diameter(const Sphere4<T>& sph) noexcept
    {   
        return sph.diameter();
    }

}
