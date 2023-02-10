////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

/* 
    This is the template IMPLEMENTATION of the vector1 code.  Include this
    *IF* you need the operator and it's not yet available as explicit 
    template instantiation.  
*/

#include <math/AxBox1.hpp>

#include <math/Multivector1.hpp>

#include <math/Segment1.hpp>

#include <math/Tensor11.hpp>
#include <math/Tensor12.hpp>
#include <math/Tensor13.hpp>
#include <math/Tensor14.hpp>

#include <math/Vector1.hpp>
#include <math/Vector2.hpp>
#include <math/Vector3.hpp>
#include <math/Vector4.hpp>

#include <math/utility.hpp>


namespace yq {
    template <typename T>
    constexpr Vector1<T>::operator glm::vec<1, T, glm::defaultp>() const noexcept
    {
        return glm::vec<1, T, glm::defaultp>(x);
    }

    template <typename T>
    constexpr Vector1<T> Vector1<T>::operator-() const noexcept
    {
        return Vector1(-x );
    }

    template <typename T>
    constexpr Vector1<T> Vector1<T>::operator~() const noexcept
    {
        if constexpr (trait::has_copysign_v<T>)
            return Vector1<T>(copysign(one_v<T>, x));
        return {};
    }

    template <typename T>
    constexpr trait::square_t<T> Vector1<T>::operator^(two_t) const noexcept
    {
        return x*x;
    }    

    template <typename T>
    constexpr Multivector1<T> Vector1<T>::operator+(T b) const noexcept
    {
        return Multivector1<T>(
            b, 
            x 
        );
    }

    template <typename T>
    constexpr AxBox1<T> Vector1<T>::operator+(const AxBox1<T>&b) const noexcept
    {
        return AxBox1<T>(*this + b.lo, *this + b.hi);
    }

    template <typename T>
    constexpr Multivector1<T> Vector1<T>::operator+(const Multivector1<T>& b) const noexcept
    {
        return Multivector1<T>(
            b.a, 
            x+b.x
        );
    }

    template <typename T>
    constexpr Segment1<T> Vector1<T>::operator+(const Segment1<T>&rhs) const noexcept
    {
        return Segment1<T>( *this + rhs.a, *this + rhs.b );
    }
    
    template <typename T>
    constexpr Vector1<T> Vector1<T>::operator+(const Vector1& b) const noexcept
    {
        return Vector1(x+b.x);
    }

    template <typename T>
    Vector1<T>& Vector1<T>::operator+=(const Vector1& b) noexcept
    {
        x += b.x;
        return *this;
    }

    template <typename T>
    std::vector<Vector1<T>> Vector1<T>::operator+(std::span<const Vector1>bs) const
    {
        return transform(bs, [&](const Vector1<T>& b) -> Vector1<T> {
            return *this + b;
        });
    }

    template <typename T>
    constexpr Multivector1<T> Vector1<T>::operator-(T b) const noexcept
    {
        return { 
            -b, 
            x 
        };
    }

    template <typename T>
    constexpr AxBox1<T> Vector1<T>::operator-(const AxBox1<T>&b) const noexcept
    {
        return AxBox1<T>(*this - b.hi, *this - b.lo);
    }

    template <typename T>
    constexpr Multivector1<T> Vector1<T>::operator-(const Multivector1<T>& b) const noexcept
    {
        return { 
            -b.a, 
            x-b.x
        };
    }

    template <typename T>
    constexpr Segment1<T> Vector1<T>::operator-(const Segment1<T>&rhs) const noexcept
    {
        return Segment1<T>( *this - rhs.a, *this - rhs.b );
    }

    template <typename T>
    constexpr Vector1<T> Vector1<T>::operator-(const Vector1& b) const noexcept
    {
        return Vector1(x-b.x);
    }

    template <typename T>
    Vector1<T>& Vector1<T>::operator-=(const Vector1& b) noexcept
    {
        x -= b.x;
        return *this;
    }

    template <typename T>
    std::vector<Vector1<T>> Vector1<T>::operator-(std::span<const Vector1>bs) const
    {
        return transform(bs, [&](const Vector1<T>& b) -> Vector1<T> {
            return *this - b;
        });
    }


    template <typename T>
        template <typename U>
    requires (trait::is_arithmetic_v<U>)
    constexpr Vector1<trait::product_t<T,U>> Vector1<T>::operator*(U b) const noexcept
    {
        return Vector1<trait::product_t<T,U>>(x*b);
    }

    template <typename T>
        template <typename U>
    requires (trait::is_arithmetic_v<U> && trait::self_mul_v<T,U>)
    Vector1<T>& Vector1<T>::operator*=(U b) noexcept
    {
        x *= b;
        return *this;
    }

    template <typename T>
        template <typename U>
    constexpr Multivector1<trait::product_t<T,U>> Vector1<T>::operator*(const Multivector1<U>& b) const noexcept
    {
        return Multivector1<T>( x * b.x, x * b.a);
    }


    template <typename T>
        template <typename U>
    constexpr Vector1<trait::product_t<T,U>> Vector1<T>::operator*(const Tensor11<U>&b) const noexcept
    {
        return Vector1<trait::product_t<T,U>>(
            x*b.xx
        );
    }

    template <typename T>
        template <typename U>
    constexpr Vector2<trait::product_t<T,U>> Vector1<T>::operator*(const Tensor12<U>&b) const noexcept
    {
        return Vector2<trait::product_t<T,U>>(
            x*b.xx,
            x*b.xy
        );
    }
    
    template <typename T>
        template <typename U>
    constexpr Vector3<trait::product_t<T,U>> Vector1<T>::operator*(const Tensor13<U>&b) const noexcept
    {
        return Vector3<trait::product_t<T,U>>(
            x*b.xx,
            x*b.xy,
            x*b.xz
        );
    }
    
    template <typename T>
        template <typename U>
    constexpr Vector4<trait::product_t<T,U>> Vector1<T>::operator*(const Tensor14<U>&b) const noexcept
    {
        return Vector4<trait::product_t<T,U>>(
            x*b.xx,
            x*b.xy,
            x*b.xz,
            x*b.xw
        );
    }
    
    template <typename T>
        template <typename U>
    requires trait::self_mul_v<T,U>
    Vector1<T>&  Vector1<T>::operator*=(const Tensor11<U>&b) noexcept
    {
        *this = *this * b;
        return *this;
    }

    template <typename T>
        template <typename U>
    constexpr trait::product_t<T,U> Vector1<T>::operator*(const Vector1<U>& b) const noexcept
    {
        return x*b.x;
    }

    template <typename T>
        template <typename U>
    constexpr trait::product_t<T,U> Vector1<T>::operator DOT (const Vector1<U>&b) const noexcept
    {
        return x*b.x;
    }

    template <typename T>
        template <typename U>
    constexpr trait::product_t<T,U>   Vector1<T>::operator INNER(const Multivector1<T>&b) const noexcept
    {
        return x * b.x;
    }

    template <typename T>
        template <typename U>
    constexpr trait::product_t<T,U> Vector1<T>::operator INNER (const Vector1<U>&b) const noexcept
    {
        return x*b.x;
    }

    template <typename T>
        template <typename U>
    constexpr Tensor11<trait::product_t<T,U>> Vector1<T>::operator OTIMES(const Vector1<U>&b) const noexcept
    {
        return Tensor11<trait::product_t<T,U>>(
            x+b.x
        );
    }

    template <typename T>
        template <typename U>
    constexpr Tensor12<trait::product_t<T,U>> Vector1<T>::operator OTIMES(const Vector2<U>&b) const noexcept
    {
        return Tensor12<trait::product_t<T,U>>(
            x+b.x, x+b.y
        );
    }

    template <typename T>
        template <typename U>
    constexpr Tensor13<trait::product_t<T,U>> Vector1<T>::operator OTIMES(const Vector3<U>&b) const noexcept
    {
        return Tensor13<trait::product_t<T,U>>(
            x+b.x, x+b.y, x+b.z
        );
    }

    template <typename T>
        template <typename U>
    constexpr Tensor14<trait::product_t<T,U>> Vector1<T>::operator OTIMES(const Vector4<U>&b) const noexcept
    {
        return Tensor14<trait::product_t<T,U>>(
            x+b.x, x+b.y, x+b.z, x+b.w
        );
    }

    template <typename T>
        template <typename U>
    requires (trait::is_arithmetic_v<U>)
    constexpr  Vector1<trait::quotient_t<T,U>> Vector1<T>::operator/(U b) const noexcept
    {
        return Vector1<trait::quotient_t<T,U>>(x / b);
    }

    template <typename T>
        template <typename U>
    requires (trait::is_arithmetic_v<U> && trait::self_div_v<T,U>)
    Vector1<T>& Vector1<T>::operator/=(U b) noexcept
    {
        x /= b;
        return *this;
    }

    template <typename T>
        template <typename U>
    constexpr trait::quotient_t<T,U> Vector1<T>::operator/(const Vector1<U>& b) const noexcept
    {
        return (*this * b)/b.length²();
    }

    template <typename T>
    constexpr AxBox1<T> Vector1<T>::operator|(const AxBox1<T>&b) const noexcept
    {
        return AxBox1<T>(UNION, {*this, b.lo, b.hi});
    }

    template <typename T>
    constexpr AxBox1<T> Vector1<T>::operator|(const Vector1&b) const noexcept
    {
        return AxBox1<T>(UNION, *this, b);
    }

    template <typename T>
    constexpr Vector1<T> Vector1<T>::all_add(T b) const noexcept
    {
        return Vector1( x + b );
    }
    
    template <typename T>
    constexpr Vector1<T> Vector1<T>::all_subtract(T b) const noexcept
    {
        return Vector1( x - b );
    }

    template <typename T>
    constexpr T Vector1<T>::cmax() const noexcept
    {
        return x;
    }
    
    template <typename T>
    constexpr T Vector1<T>::cmin() const noexcept
    {
        return x;
    }

    template <typename T>
    constexpr T Vector1<T>::cproduct() const noexcept
    {
        return x;
    }

    template <typename T>
    constexpr T Vector1<T>::csum() const noexcept
    {
        return x;
    }
    
    template <typename T>
    constexpr Vector1<T>   Vector1<T>::eabs() const noexcept
    {
        return Vector1(abs(x));
    }

    template <typename T>
        template <typename U>
    constexpr Vector1<trait::quotient_t<T,U>>    Vector1<T>::ediv(const Vector1<U>&b) const noexcept
    {
        return Vector1<trait::quotient_t<T,U>>(x/b.x);
    }

    template <typename T>
    constexpr Vector1<T>   Vector1<T>::emax(const Vector1&b) const noexcept
    {
        return Vector1(max(x, b.x));
    }

    template <typename T>
    constexpr Vector1<T>   Vector1<T>::emax(T b) const noexcept
    {
        return Vector1(max(x, b));
    }

    template <typename T>
    constexpr Vector1<T>   Vector1<T>::emin(const Vector1&b) const noexcept
    {
        return Vector1(min(x, b.x));
    }

    template <typename T>
    constexpr Vector1<T>   Vector1<T>::emin(T b) const noexcept
    {
        return Vector1(min(x, b));
    }

    template <typename T>
        template <typename U>
    constexpr Vector1<trait::product_t<T,U>>    Vector1<T>::emul(const Vector1<U>&b) const noexcept
    {
        return Vector1<trait::product_t<T,U>>(x*b.x);
    }

    template <typename T>
    constexpr trait::square_t<T> Vector1<T>::length²() const noexcept
    {
        return x*x;
    }    

    template <typename T>
    constexpr T    Vector1<T>::length() const noexcept
    {
        if constexpr (trait::has_abs_v<T>)
            return abs(x);
        if(x < T{})
            return -x;
        return x;
    }

    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    template <typename T>
    constexpr Multivector1<T> operator+(T a, const Vector1<T>& b) noexcept
    {
        return { 
            a, 
            b.x 
        };
    }

    template <typename T>
    std::vector<Vector1<T>>   operator+(std::span<Vector1<T>>as, Vector1<T>b)
    {
        return transform(as, [&](const Vector1<T>&a) -> Vector1<T> {
            return a + b;
        });
    }

    template <typename T>
    constexpr Multivector1<T> operator-(T a, const Vector1<T>& b) noexcept
    {
        return { 
            a, 
            -b.x 
        };
    }

    template <typename T>
    std::vector<Vector1<T>>   operator-(std::span<Vector1<T>>as, Vector1<T>b)
    {
        return transform(as, [&](const Vector1<T>&a) -> Vector1<T> {
            return a - b;
        });
    }

    template <typename T, typename U>
    requires (trait::is_arithmetic_v<T>)
    constexpr Vector1<trait::product_t<T,U>> operator*(T a, const Vector1<U>&b) noexcept
    {
        return Vector1<trait::product_t<T,U>>(a*b.x);
    }

    template <typename T, typename U>
    std::vector<Vector1<trait::product_t<T,U>>> operator*(std::span<const Vector1<T>>as, const Tensor11<U>&b)
    {
        return transform(as, [&](const Vector1<T>&v) -> Vector1<trait::product_t<T,U>>{
            return v * b;
        });
    }
    
    template <typename T, typename U>
    std::vector<Vector2<trait::product_t<T,U>>> operator*(std::span<const Vector1<T>>as, const Tensor12<U>&b)
    {
        return transform(as, [&](const Vector1<T>&v) -> Vector2<trait::product_t<T,U>>{
            return v * b;
        });
    }

    template <typename T, typename U>
    std::vector<Vector3<trait::product_t<T,U>>> operator*(std::span<const Vector1<T>>as, const Tensor13<U>&b)
    {
        return transform(as, [&](const Vector1<T>&v) -> Vector3<trait::product_t<T,U>>{
            return v * b;
        });
    }
    
    template <typename T, typename U>
    std::vector<Vector4<trait::product_t<T,U>>> operator*(std::span<const Vector1<T>>as, const Tensor14<U>&b)
    {
        return transform(as, [&](const Vector1<T>&v) -> Vector4<trait::product_t<T,U>>{
            return v * b;
        });
    }

    template <typename T, typename U>
    requires (trait::is_arithmetic_v<T>)
    constexpr  Vector1<trait::quotient_t<T,U>> operator/(T a, const  Vector1<U>&b) noexcept
    {
        return (a*b) / b.length²();
    }

    template <typename T>
    constexpr Vector1<T>   abs_elem(const Vector1<T>&a) noexcept
    {
        return a.eabs();
    }

    template <typename T>
    constexpr T             component_max(const Vector1<T>&a) noexcept
    {
        return a.x;
    }

    template <typename T>
    constexpr T             component_min(const Vector1<T>&a) noexcept
    {
        return a.x;
    }

    template <typename T>
    constexpr T                   component_product(const Vector1<T>& a) noexcept
    {
        return a.x;
    }

    template <typename T>
    constexpr T                   component_sum(const Vector1<T>& a) noexcept
    {
        return a.x;
    }
    
    template <typename T, typename U>
    constexpr Vector1<trait::quotient_t<T,U>>    div_elem(const Vector1<T>&a, const Vector1<U>&b) noexcept
    {
        return a.ediv(b);
    }

    template <typename T>
    constexpr trait::square_t<T> length²(const Vector1<T>& vec) noexcept
    {
        return vec.length²();
    }    
    

    template <typename T>
    constexpr T  length(const Vector1<T>& vec) noexcept
    {
        return vec.length();
    }

    template <typename T>
    constexpr Vector1<T>   max_elem(const Vector1<T>&a, const Vector1<T>&b) noexcept
    {
        return a.emax(b);
    }

    template <typename T>
    constexpr Vector1<T>   max_elem(std::initializer_list<Vector1<T>> vs) noexcept
    {
        return max_elem(std::span<const Vector1<T>>(vs.data(), vs.size()));
    }

    template <typename T>
    constexpr Vector1<T>   max_elem(std::span<const Vector1<T>>vs) noexcept
    {
        if(vs.empty())
            return Vector1<T>(NAN);
        return Vector1<T>(
            std::max_element(vs.begin(), vs.end(), Vector1<T>::less_x) -> x
        );
    }


    /*! \brief Mid-way divide two vectors
    */
    template <typename T>
    constexpr Vector1<T>        midvector(const Vector1<T>& a, const Vector1<T>& b) noexcept
    {
        if constexpr (has_ieee754_v<T>)
            return ieee754_t<T>(0.5)*(a+b);
        else if constexpr (std::is_integral_v<T>)
            return (a+b) / T(2);
        else
            return {};
    }
    
    template <typename T>
    constexpr Vector1<T>   min_elem(const Vector1<T>&a, const Vector1<T>&b) noexcept
    {
        return a.emin(b);
    }

    template <typename T>
    constexpr Vector1<T>   min_elem(std::initializer_list<Vector1<T>>vs) noexcept
    {
        return min_elem(std::span<const Vector1<T>>(vs.data(), vs.size()));
    }

    template <typename T>
    constexpr Vector1<T>   min_elem(std::span<const Vector1<T>>vs) noexcept
    {
        if(vs.empty())
            return Vector1<T>(NAN);
        return Vector1<T>(
            std::min_element(vs.begin(), vs.end(), Vector1<T>::less_x) -> x
        );
    }

    template <typename T, typename U>
    constexpr Vector1<trait::product_t<T,U>>    mul_elem(const Vector1<T>&a, const Vector1<U>&b) noexcept
    {
        return a.emul(b);
    }

}
