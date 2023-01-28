////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

/* 
    This is the template IMPLEMENTATION of the vector4 code.  Include this
    *IF* you need the operator and it's not yet available as explicit 
    template instantiation.  
*/

#include "Bivector4.hpp"
#include "Multivector4.hpp"
#include "Quadvector4.hpp"
#include "Trivector4.hpp"

#include "Vector1.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

#include "Tensor41.hpp"
#include "Tensor42.hpp"
#include "Tensor43.hpp"
#include "Tensor44.hpp"

namespace yq {
    template <typename T>
    constexpr Vector4<T>::operator glm::vec<4, T, glm::defaultp>() const noexcept
    {
        return glm::vec<4, T, glm::defaultp>( x, y, z, w );
    }

    template <typename T>
    constexpr Vector4<T> Vector4<T>::operator-() const noexcept
    {
        return Vector4(-x,-y,-z,-w);
    }

    template <typename T>
    Vector4<quotient_t<T,T>> Vector4<T>::operator~() const
    {
        auto l = one_v<T>/length();
        return Vector4(x*l, y*l, z*l, w*l);
    }

    template <typename T>
    constexpr square_t<T> Vector4<T>::operator^(two_t) const noexcept
    {
        return x*x + y*y + z*z + w*w;
    }    

    template <typename T>
    constexpr Multivector4<T> Vector4<T>::operator+(const Bivector4<T>&b) const noexcept
    {
        return Multivector4<T>(
            {}, 
            x, y, z, w, 
            b.xy, b.yz, b.zw, b.wx, b.xz, b.yw,
            {}, {}, {}, {}, 
            {} 
        );
    }

    template <typename T>
    constexpr Multivector4<T> Vector4<T>::operator+(const Multivector4<T>&b) const noexcept
    {
        return Multivector4<T>(
            b.a, 
            x+b.x, y+b.y, z+b.z, w+b.w, 
            b.xy, b.yz, b.zw, b.wx, b.xz, b.yw,
            b.xyz, b.yzw, b.zwx, b.wxy,
            b.xyzw
        );
    }

    template <typename T>
    constexpr Multivector4<T> Vector4<T>::operator+(const Quadvector4<T>&b) const noexcept
    {
        return Multivector4<T>(
            {}, 
            x, y, z, w, 
            {}, {}, {}, {}, {}, {}, 
            {}, {}, {}, {}, 
            b.xyzw
        );
    }

    template <typename T>
    constexpr Multivector4<T> Vector4<T>::operator+(const Trivector4<T>&b) const noexcept
    {
        return Multivector4<T>(
            {}, 
            x, y, z, w, 
            {}, {}, {}, {}, {}, {}, 
            b.xyz, b.yzw, b.zwx, b.wxy,
            {} 
        );
    }

    template <typename T>
    constexpr Multivector4<T> Vector4<T>::operator+(T b) const noexcept
    {
        return Multivector4<T>(
            b, 
            x, y, z, w, 
            {}, {}, {}, {}, {}, {}, 
            {}, {}, {}, {}, 
            {} 
        );
    }

    template <typename T>
    constexpr Vector4<T> Vector4<T>::operator+(const Vector4& b) const noexcept
    {
        return Vector4(x+b.x, y+b.y, z+b.z, w+b.w);
    }

    template <typename T>
    Vector4<T>& Vector4<T>::operator+=(const Vector4& b) noexcept
    {
        x += b.x;
        y += b.y;
        z += b.z;
        w += b.w;
        return *this;
    }

    template <typename T>
    constexpr Vector4<T> Vector4<T>::operator-(const Vector4& b) const noexcept
    {
        return Vector4(x-b.x, y-b.y, z-b.z, w-b.w);
    }
    
    template <typename T>
    Vector4<T>& Vector4<T>::operator-=(const Vector4& b) noexcept
    {
        x -= b.x;
        y -= b.y;
        z -= b.z;
        w -= b.w;
        return *this;
    }


    template <typename T>
    constexpr Multivector4<T> Vector4<T>::operator-(T b) const noexcept
    {
        return { 
            -b, 
            x, y, z, w, 
            {}, {}, {}, {}, {}, {}, 
            {}, {}, {}, {}, 
            {} 
        };
    }

    template <typename T>
    constexpr Multivector4<T> Vector4<T>::operator-(const Bivector4<T>& b) const noexcept
    {
        return { 
            {}, 
            x, y, z, w, 
            -b.xy, -b.yz, -b.zw, -b.wx, -b.xz, -b.yw,
            {}, {}, {}, {}, 
            {} 
        };
    }

    template <typename T>
    constexpr Multivector4<T> Vector4<T>::operator-(const Multivector4<T>& b) const noexcept
    {
        return { 
            -b.a, 
            x-b.x, y-b.y, z-b.z, w-b.w, 
            -b.xy, -b.yz, -b.zw, -b.wx, -b.xz, -b.yw,
            -b.xyz, -b.yzw, -b.zwx, -b.wxy,
            -b.xyzw
        };
    }

    template <typename T>
    constexpr Multivector4<T> Vector4<T>::operator-(const Quadvector4<T>& b) const noexcept
    {
        return { 
            {}, 
            x, y, z, w, 
            {}, {}, {}, {}, {}, {}, 
            {}, {}, {}, {}, 
            -b.xyzw
        };
    }

    template <typename T>
    constexpr Multivector4<T> Vector4<T>::operator-( const Trivector4<T>& b) const noexcept
    {
        return { 
            {}, 
            x, y, z, w, 
            {}, {}, {}, {}, {}, {}, 
            -b.xyz, -b.yzw, -b.zwx, -b.wxy,
            {} 
        };
    }    

    template <typename T>
        template <typename U>
    requires (trait::is_arithmetic_v<U>)
    constexpr Vector4<product_t<T,U>> Vector4<T>::operator*(U b) const noexcept
    {
        return Vector4<product_t<T,U>>(x*b, y*b, z*b, w*b);
    }

    template <typename T>
        template <typename U>
    constexpr Vector1<product_t<T,U>> Vector4<T>::operator*(const Tensor41<U>&b) const noexcept
    {
        return Vector1<product_t<T,U>>(
            x*b.xx + y*b.yx + z*b.zx + w*b.wx
        );
    }

    template <typename T>   
        template <typename U>
    constexpr Vector2<product_t<T,U>> Vector4<T>::operator*(const Tensor42<U>&b) const noexcept
    {
        return Vector2<product_t<T,U>>(
            x*b.xx + y*b.yx + z*b.zx + w*b.wx,
            x*b.xy + y*b.yy + z*b.zy + w*b.wy
        );
    }

    template <typename T>
        template <typename U>
    constexpr Vector3<product_t<T,U>> Vector4<T>::operator*(const Tensor43<U>&b) const noexcept
    {
        return Vector3<product_t<T,U>>(
            x*b.xx + y*b.yx + z*b.zx + w*b.wx,
            x*b.xy + y*b.yy + z*b.zy + w*b.wy,
            x*b.xz + y*b.yz + z*b.zz + w*b.wz
        );
    }

    template <typename T>
        template <typename U>
    constexpr Vector4<product_t<T,U>> Vector4<T>::operator*(const Tensor44<U>&b) const noexcept
    {
        return Vector4<product_t<T,U>>(
            x*b.xx + y*b.yx + z*b.zx + w*b.wx,
            x*b.xy + y*b.yy + z*b.zy + w*b.wy,
            x*b.xz + y*b.yz + z*b.zz + w*b.wz,
            x*b.xw + y*b.yw + z*b.zw + w*b.ww
        );
    }

    template <typename T>
        template <typename U>
    requires trait::self_mul_v<T,U>
    Vector4<T>& Vector4<T>::operator*=(const Tensor44<U>& b) noexcept
    {
        *this = *this * b;
        return *this;
    }

    template <typename T>
        template <typename U>
    constexpr Multivector4<product_t<T,U>>   Vector4<T>::operator*(const Vector4<U>&b) const noexcept
    {
        return (*this INNER b) + (*this OUTER b);
    }

    template <typename T>
        template <typename U>
    requires (trait::is_arithmetic_v<U> && trait::self_mul_v<T,U>)
    Vector4<T>& Vector4<T>::operator*=(U b) noexcept
    {
        x *= b;
        y *= b;
        z *= b;
        w *= b;
        return *this;
    }

    template <typename T>
        template<typename U>
    constexpr product_t<T,U> Vector4<T>::operator DOT (const Vector4<U>&b) const noexcept
    {
        return x*b.x + y*b.y + z*b.z + w*b.w;
    }


    template <typename T>
        template<typename U>
    constexpr product_t<T,U> Vector4<T>::operator INNER (const Vector4<U>&b) const noexcept
    {
        return x*b.x + y*b.y + z*b.z + w*b.w;
    }

    template <typename T>
        template <typename U>
    constexpr Bivector4<product_t<T,U>> Vector4<T>::operator OUTER(const Vector4<U>&b) const noexcept
    {
        return { x*b.y-y*b.x, y*b.z-z*b.y, z*b.w-w*b.z, w*b.x-x*b.w, x*b.z-z*b.x, y*b.w-w*b.y };
    }

    template <typename T>
        template <typename U>
    constexpr Tensor41<product_t<T,U>> Vector4<T>::operator OTIMES(const Vector1<U>&b) const noexcept
    {
        return Tensor41<product_t<T,U>>(
            x+b.x,
            y+b.x,
            z+b.x,
            w+b.x
        );
    }

    template <typename T>
        template <typename U>
    constexpr Tensor42<product_t<T,U>> Vector4<T>::operator OTIMES(const Vector2<U>&b) const noexcept
    {
        return Tensor42<product_t<T,U>>(
            x+b.x, x+b.y,
            y+b.x, y+b.y,
            z+b.x, z+b.y,
            w+b.x, w+b.y
        );
    }
    
    template <typename T>
        template <typename U>
    constexpr Tensor43<product_t<T,U>> Vector4<T>::operator OTIMES(const Vector3<U>&b) const noexcept
    {
        return Tensor43<product_t<T,U>>(
            x+b.x, x+b.y, x+b.z,
            y+b.x, y+b.y, y+b.z,
            z+b.x, z+b.y, z+b.z,
            w+b.x, w+b.y, w+b.z
        );
    }

    template <typename T>
        template <typename U>
    constexpr Tensor44<product_t<T,U>> Vector4<T>::operator OTIMES(const Vector4<U>&b) const noexcept
    {
        return Tensor44<product_t<T,U>>(
            x+b.x, x+b.y, x+b.z, x+b.w,
            y+b.x, y+b.y, y+b.z, y+b.w,
            z+b.x, z+b.y, z+b.z, z+b.w,
            w+b.x, w+b.y, w+b.z, w+b.w
        );
    }

    template <typename T>
        template <typename U>
    requires (trait::is_arithmetic_v<U>)
    constexpr  Vector4<quotient_t<T,U>> Vector4<T>::operator/(U b) const noexcept
    {
        return Vector4<quotient_t<T,U>>(x / b, y / b, z / b, w / b);
    }
    
    template <typename T>
        template <typename U>
    requires (trait::is_arithmetic_v<U> && trait::self_div_v<T,U>)
    Vector4<T>& Vector4<T>::operator/=(U b) noexcept
    {
        x /= b;
        y /= b;
        z /= b;
        w /= b;
        return *this;
    }

    template <typename T>
    constexpr Vector4<T> Vector4<T>::all_add(T b) const noexcept
    {
        return Vector4( x+b, y+b, z+b, w+b );
    }
    
    template <typename T>
    constexpr Vector4<T> Vector4<T>::all_subtract(T b) const noexcept
    {
        return Vector4( x-b, y-b, z-b, w-b );
    }

    template <typename T>
    constexpr T     Vector4<T>::cmax() const noexcept
    {
        return max(max(x, y), max(z, w));
    }

    template <typename T>
    constexpr T     Vector4<T>::cmin() const noexcept
    {
        return min(min(x, y), min(z, w));
    }

    template <typename T>
    constexpr fourth_t<T>   Vector4<T>::cproduct() const noexcept
    {
        return x*y*z*w;
    }

    template <typename T>
    constexpr T             Vector4<T>::csum() const noexcept
    {
        return x + y + z + w;
    }

    template <typename T>
    constexpr Vector4<T>   Vector4<T>::eabs() const noexcept
    {
        return Vector4( abs(x), abs(y), abs(z), abs(w) );
    }

    template <typename T>
        template <typename U>
    constexpr Vector4<quotient_t<T,U>>  Vector4<T>::ediv(const Vector4<U>&b) const noexcept
    {
        return Vector4<quotient_t<T,U>>(x/b.x, y/b.y, z/b.z, w/b.w);
    }

    template <typename T>
    constexpr Vector4<T>   Vector4<T>::emax(const Vector4&b) const noexcept
    {
        return Vector4(max(x, b.x), max(y, b.y), max(z, b.z), max(w, b.w));
    }
    
    template <typename T>
    constexpr Vector4<T>   Vector4<T>::emin(const Vector4&b) const noexcept
    {
        return Vector4(min(x, b.x), min(y, b.y), min(z, b.z), min(w, b.w));
    }

    template <typename T>
        template <typename U>
    constexpr Vector4<product_t<T,U>>   Vector4<T>::emul(const Vector4<U>&b) const noexcept
    {
        return {x*b.x, y*b.y, z*b.z, w*b.w};
    }
        
    template <typename T>
    constexpr square_t<T> Vector4<T>::length²() const noexcept
    {
        return x*x + y*y + z*z + w*w;
    }    

    template <typename T>
    T    Vector4<T>::length() const
    {
        if constexpr (trait::has_sqrt_v<T>)
            return sqrt(length²());
        return {};
    }

    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


    template <typename T>
    constexpr square_t<T> length²(const Vector4<T>& a) noexcept
    {
        return a.length²();
    }    

    template <typename T>
    auto    length(const Vector4<T>& a)
    {
        return a.length();
    }

}
