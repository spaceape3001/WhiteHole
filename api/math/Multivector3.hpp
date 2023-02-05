////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <math/preamble.hpp>
#include <math/Vector3.hpp>
#include <math/Bivector3.hpp>
#include <math/Trivector3.hpp>

namespace yq {

    /*! \brief Three dimensional multivector
    */
    template <typename T>
    struct Multivector3 {
        //! Captures the template parameter
        using component_type    = T;

        T   a;
        T   x, y, z;
        T   xy, yz, zx;
        T   xyz;
        
        constexpr Multivector3() noexcept = default;
        constexpr Multivector3(T _a, T _x, T _y, T _z, T _xy, T _yz, T _zx, T _xyz) noexcept : 
            a(_a), x(_x), y(_y), z(_z), xy(_xy), yz(_yz), zx(_zx), xyz(_xyz) {}
        constexpr Multivector3(T _a, const Vector3<T>& v, const Bivector3<T>& b, const Trivector3<T>& t) noexcept : 
            a(_a), x(v.x), y(v.y), z(v.z), xy(b.xy), yz(b.yz), zx(b.zx), xyz(t.xyz) {}
        constexpr Multivector3(all_t, T v) noexcept : a(v), x(v), y(v), z(v), xy(v), yz(v), zx(v), xyz(v) {}
        template <typename=void> requires trait::has_nan_v<T>
        consteval Multivector3(nan_t) noexcept : Multivector3(ALL, nan_v<T>) {}
        consteval Multivector3(one_t) noexcept : Multivector3(ALL, one_v<T>) {}
        consteval Multivector3(zero_t) noexcept : Multivector3(ALL, zero_v<T>) {}

        constexpr bool operator==(const Multivector3&) const noexcept = default;

        constexpr Multivector3 operator+() const noexcept;
        constexpr Multivector3 operator-() const noexcept;

        constexpr Multivector3  operator+(T b) const noexcept;
        Multivector3&           operator+=(T b) noexcept;
        constexpr Multivector3  operator+(const Bivector3<T>& b) const noexcept;
        Multivector3&           operator+=(const Bivector3<T>& b) noexcept;
        constexpr Multivector3  operator+(const Multivector3& b) const noexcept;
        Multivector3&           operator+=(const Multivector3& b) noexcept;
        constexpr Multivector3  operator+(const Trivector3<T>& b) const noexcept;
        Multivector3&           operator+=(const Trivector3<T>& b) noexcept;
        constexpr Multivector3  operator+(const Vector3<T>&  b) const noexcept;
        Multivector3&           operator+=(const Vector3<T>& b) noexcept;

        constexpr Multivector3  operator-(T b) const noexcept;
        Multivector3&           operator-=(T b) noexcept;
        constexpr Multivector3  operator-(const Bivector3<T>& b) const noexcept;
        Multivector3&           operator-=(const Bivector3<T>& b) noexcept;
        constexpr Multivector3  operator-(const Multivector3& b) const noexcept;
        Multivector3&           operator-=(const Multivector3& b) noexcept;
        constexpr Multivector3  operator-(const Trivector3<T>& b) const noexcept;
        Multivector3&           operator-=(const Trivector3<T>& b) noexcept;
        constexpr Multivector3  operator-(const Vector3<T>&  b) const noexcept;
        Multivector3&           operator-=(const Vector3<T>& b) noexcept;

        template <typename U>
        requires trait::is_arithmetic_v<U>
        constexpr Multivector3<trait::product_t<T,U>> operator*(U b) const noexcept;

        template <typename U>
        requires (trait::is_arithmetic_v<U> && trait::self_mul_v<T,U>)
        Multivector3& operator*=(U b) noexcept;

        template <typename U>
        requires trait::is_arithmetic_v<U>
        constexpr Multivector3<trait::quotient_t<T,U>> operator/(U b) const noexcept;

        template <typename U>
        requires (trait::is_arithmetic_v<U> && trait::self_div_v<T,U>)
        Multivector3& operator/=(U b) noexcept;

        constexpr Bivector3<T>  bivector() const noexcept;
        constexpr Trivector3<T> trivector() const noexcept;
        constexpr Vector3<T>    vector() const noexcept;
    };

    YQ_IEEE754_1(Multivector3)

//  --------------------------------------------------------
//  COMPOSITION

    YQ_NAN_1(Multivector3, Multivector3<T>(NAN))
    YQ_ZERO_1(Multivector3, Multivector3<T>(ZERO))

//  --------------------------------------------------------
//  GETTERS

    template <typename T>
    constexpr Bivector3<T> bivector(const Multivector3<T>& a) noexcept;

    template <typename T>
    constexpr Trivector3<T> trivector(const Multivector3<T>& a) noexcept;

    template <typename T>
    constexpr Vector3<T> vector(const Multivector3<T>& a) noexcept;
    
//  --------------------------------------------------------
//  BASIC FUNCTIONS
    
    YQ_IS_NAN_1(Multivector3, 
        is_nan(v.a) || 
        is_nan(v.x) || is_nan(v.y) || is_nan(v.z) || 
        is_nan(v.xy) || is_nan(v.yz) || is_nan(v.zx) || 
        is_nan(v.xyz)
    )
    YQ_IS_FINITE_1(Multivector3, 
        is_finite(v.a) && 
        is_finite(v.x) && is_finite(v.y) && is_finite(v.z) && 
        is_finite(v.xy) && is_finite(v.yz) && is_finite(v.zx) && 
        is_finite(v.xyz)
    )


//  --------------------------------------------------------
//  --------------------------------------------------------

    
    template <typename T>
    constexpr Multivector3<T> operator+(T a, const Multivector3<T>& b) noexcept;
    template <typename T>
    constexpr Multivector3<T> operator-(T a, const Multivector3<T>& b) noexcept;

    template <typename T, typename U>
    requires trait::is_arithmetic_v<T>
    constexpr Multivector3<trait::product_t<T,U>> operator*(T a, const Multivector3<U>&b) noexcept;



}

YQ_TYPE_DECLARE(Multivector3D)
YQ_TYPE_DECLARE(Multivector3F)
