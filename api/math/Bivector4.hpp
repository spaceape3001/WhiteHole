////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#define YQ_MATH_BIVECTOR4_HPP 1

#include <math/preamble.hpp>

namespace yq {
    /*! \brief Four dimensional bivector
    
        Bivector for four dimensions.
    */
    template <typename T>
    struct Bivector4 {

        //! Component type
        using component_type = T;
        
        //! Components
        T     xy, yz, zw, wx, xz, yw;

        constexpr Bivector4() noexcept = default;
        constexpr Bivector4(T _xy, T _yz, T _zw, T _wx, T _xz, T _yw) noexcept : 
            xy(_xy), yz(_yz), zw(_zw), wx(_wx), xz(_xz), yw(_yw) {}
        constexpr Bivector4(all_t, T v) noexcept : xy(v), yz(v), zw(v), wx(v), xz(v), yw(v) {}
        consteval Bivector4(nan_t) noexcept : Bivector4(ALL, nan_v<T>) {}
        consteval Bivector4(one_t) noexcept : Bivector4(ALL, one_v<T>) {}
        constexpr Bivector4(xy_t, T v) noexcept : 
            xy(v), yz(zero_v<T>), zw(zero_v<T>), wx(zero_v<T>), xz(zero_v<T>), yw(zero_v<T>) {}
        consteval Bivector4(xy_t) noexcept : Bivector4(XY, one_v<T>) {}
        constexpr Bivector4(yz_t, T v) noexcept : 
            xy(zero_v<T>), yz(v), zw(zero_v<T>), wx(zero_v<T>), xz(zero_v<T>), yw(zero_v<T>) {}
        consteval Bivector4(yz_t) noexcept : Bivector4(YZ, one_v<T>) {}
        constexpr Bivector4(zw_t, T v) noexcept : 
            xy(zero_v<T>), yz(zero_v<T>), zw(zero_v<T>), wx(v), xz(zero_v<T>), yw(zero_v<T>) {}
        consteval Bivector4(zw_t) noexcept : Bivector4(ZW, one_v<T>) {}
        constexpr Bivector4(wx_t, T v) noexcept : 
            xy(zero_v<T>), yz(zero_v<T>), zw(zero_v<T>), wx(v), xz(zero_v<T>), yw(zero_v<T>) {}
        consteval Bivector4(wx_t) noexcept : Bivector4(WX, one_v<T>) {}
        constexpr Bivector4(xz_t, T v) noexcept : 
            xy(zero_v<T>), yz(zero_v<T>), zw(zero_v<T>), wx(zero_v<T>), xz(v), yw(zero_v<T>) {}
        consteval Bivector4(xz_t) noexcept : Bivector4(XZ, one_v<T>) {}
        constexpr Bivector4(yw_t, T v) noexcept : 
            xy(zero_v<T>), yz(zero_v<T>), zw(zero_v<T>), wx(zero_v<T>), xz(zero_v<T>), yw(v) {}
        consteval Bivector4(yw_t) noexcept : Bivector4(YW, one_v<T>) {}
        consteval Bivector4(zero_t) noexcept : Bivector4(ALL, zero_v<T>) {}

        template <typename U>
        requires std::is_nothrow_convertible_v<T,U>
        explicit constexpr operator Bivector4<U>() const noexcept
        {
            return { (U) xy, (U) yz, (U) zw, (U) wx, (U) xz, (U) yw };
        }
        
        template <typename U>
        requires (std::is_convertible_v<T,U> && !std::is_nothrow_convertible_v<T,U>)
        explicit constexpr operator Bivector4<U>() const 
        {
            return { (U) xy, (U) yz, (U) zw, (U) wx, (U) xz, (U) yw };
        }

        //! Defaulted comparison operator
        bool operator==(const Bivector4&) const noexcept = default;
        
        constexpr Bivector4 operator+() const noexcept;
        constexpr Bivector4 operator-() const noexcept;

        constexpr Multivector4<T> operator+(T b) const noexcept;
        constexpr Bivector4 operator+(const Bivector4& b) const noexcept;
        Bivector4&       operator+=(const Bivector4&b) noexcept;
        constexpr Multivector4<T> operator+(const Multivector4<T>& b) const noexcept;
        constexpr Multivector4<T> operator+(const Quadvector4<T>& b) const noexcept;
        constexpr Multivector4<T> operator+(const Trivector4<T>& b) const noexcept;
        constexpr Multivector4<T> operator+(const Vector4<T>& b) const noexcept;

        constexpr Multivector4<T> operator-(T b) const noexcept;
        constexpr Bivector4 operator-(const Bivector4& b) const noexcept;
        Bivector4&       operator-=(const Bivector4&b) noexcept;
        constexpr Multivector4<T> operator-(const Multivector4<T>& b) const noexcept;
        constexpr Multivector4<T> operator-(const Quadvector4<T>& b) const noexcept;
        constexpr Multivector4<T> operator-(const Trivector4<T>& b) const noexcept;
        constexpr Multivector4<T> operator-(const Vector4<T>& b) const noexcept;

        template <typename U>
        requires is_arithmetic_v<U>
        constexpr Bivector4<product_t<T,U>> operator*(U b) const noexcept;

        template <typename U>
        requires (is_arithmetic_v<U> && self_mul_v<T,U>)
        Bivector4& operator*=(U b) noexcept;

        template <typename U>
        requires is_arithmetic_v<U>
        constexpr Bivector4<quotient_t<T,U>> operator/(U b) const noexcept;

        template <typename U>
        requires (is_arithmetic_v<U> && self_div_v<T,U>)
        Bivector4& operator/=(U b) noexcept;
    };
    
    YQ_IEEE754_1(Bivector4)
    YQ_INTEGER_1(Bivector4)
    YQ_IS_INTEGER_1(Bivector4)


//  --------------------------------------------------------
//  COMPOSITION

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _xy4(unsigned long long int v) noexcept
    {
        return Bivector4D(XY, (double) v);
    }

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _xy4(long double v) noexcept
    {
        return Bivector4D(XY, (double) v);
    }

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _yz4(unsigned long long int v) noexcept
    {
        return Bivector4D(YZ, (double) v);
    }

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _yz4(long double v) noexcept
    {
        return Bivector4D(YZ, (double) v);
    }

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _zw4(unsigned long long int v) noexcept
    {
        return Bivector4D(ZW, (double) v);
    }

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _xw4(long double v) noexcept
    {
        return Bivector4D(ZW, (double) v);
    }

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _wx4(unsigned long long int v) noexcept
    {
        return Bivector4D(WX, (double) v);
    }

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _wx4(long double v) noexcept
    {
        return Bivector4D(WX, (double) v);
    }

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _xz4(unsigned long long int v) noexcept
    {
        return Bivector4D(XZ, (double) v);
    }

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _xz4(long double v) noexcept
    {
        return Bivector4D(XZ, (double) v);
    }

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _yw4(unsigned long long int v) noexcept
    {
        return Bivector4D(YW, (double) v);
    }

    /*! \brief Literal constructor
    */
    constexpr Bivector4D   operator "" _yw4(long double v) noexcept
    {
        return Bivector4D(YW, (double) v);
    }
    
    YQ_NAN_1(Bivector4, Bivector4<T>(NAN))
    YQ_ZERO_1(Bivector4, Bivector4<T>(ZERO))

//  --------------------------------------------------------
//  BASIC FUNCTIONS
    
    YQ_IS_NAN_1(Bivector4, 
        is_nan(v.xy) || is_nan(v.yz) || is_nan(v.zw) || 
        is_nan(v.wx) || is_nan(v.xz) || is_nan(v.yw)
    )
    YQ_IS_FINITE_1(Bivector4, 
        is_finite(v.xy) && is_finite(v.yz) && is_finite(v.zw) && 
        is_finite(v.wx) && is_finite(v.xz) && is_finite(v.yw)
    )


//  --------------------------------------------------------
//  --------------------------------------------------------

    template <typename T>
    constexpr Multivector4<T> operator+(T a, const Bivector4<T>& b) noexcept;

    template <typename T>
    constexpr Multivector4<T> operator-(T a, const Bivector4<T>& b) noexcept;

    template <typename T, typename U>
    requires is_arithmetic_v<T>
    constexpr Bivector4<product_t<T,U>> operator*(T a, const Bivector4<U>& b) noexcept;


}

YQ_TYPE_DECLARE(yq::Bivector4D)
YQ_TYPE_DECLARE(yq::Bivector4F)

