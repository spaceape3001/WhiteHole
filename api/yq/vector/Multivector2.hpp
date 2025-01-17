////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#define YQ_MATH_MULTIVECTOR2_HPP 1


#include <yq/typedef/multivector2.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Bivector2.hpp>

#include <yq/keywords.hpp>
#include <yq/trait/product.hpp>
#include <yq/trait/quotient.hpp>
#include <yq/trait/self_divide.hpp>
#include <yq/trait/self_multiply.hpp>

namespace log4cpp { class CategoryStream; }

namespace yq {

    /*! \brief Two dimensional multivector
    */
    template <typename T>
    struct Multivector2 {

        //! Captures the template parameter
        using component_type    = T;

        //! Scalar
        T               a;
        
        //! X (vector component)
        T               x;
        
        //! Y (vector component)
        T               y;
        
        //! XY (bivector component)
        T               xy;
        
        //! Default constructor
        constexpr Multivector2() noexcept = default;
        
        //! Constructs by scalar parts
        constexpr Multivector2(T _a, T _x, T _y, T _xy) noexcept : a(_a), x(_x), y(_y), xy(_xy) {}
        
        //! Constructs by components (scalar, vector, bivector)
        constexpr Multivector2(T _a, const Vector2<T>& v, const Bivector2<T>& b) noexcept : a(_a), x(v.x), y(v.y), xy(b.xy) {}
        
        //! Constructs by setting all components to the same value
        constexpr Multivector2(all_k, T v) noexcept : a(v), x(v), y(v), xy(v) {}
        
        //! Constructs all elements to Not-a-number
        template <typename=void> requires has_nan_v<T>
        consteval Multivector2(nan_k) noexcept : Multivector2(ALL, nan_v<T>) {}
        
        //! Constructs all elements to be one
        consteval Multivector2(one_k) noexcept : Multivector2(ALL, one_v<T>) {}
        
        //! Constructs all elements to be zero
        consteval Multivector2(zero_k) noexcept : Multivector2(ALL, zero_v<T>) {}

        //! Converts this multivector to another multivector2 of compatible data type
        template <typename U>
        requires std::is_nothrow_convertible_v<T,U>
        explicit constexpr operator Multivector2<U>() const noexcept
        {
            return {
                (U) a,
                (U) x, (U) y,
                (U) xy
            };
        }
        
        //! Converts this multivector to another multivector2 of compatible data type
        template <typename U>
        requires (std::is_convertible_v<T,U> && !std::is_nothrow_convertible_v<T,U>)
        explicit constexpr operator Multivector2<U>() const 
        {
            return {
                (U) a,
                (U) x, (U) y,
                (U) xy
            };
        }

        //! Defaulted equality operator
        constexpr bool operator==(const Multivector2&) const noexcept = default;

        //! Positive (affirmation) operator
        constexpr Multivector2<T> operator+() const noexcept;
        
        //! Negation operator
        constexpr Multivector2<T> operator-() const noexcept;
        
        //! Adds scalar to multivector
        constexpr Multivector2<T> operator+(T b) const noexcept;

        //! Self adds scalar to this multivector, returns a reference to self
        Multivector2<T>& operator+=(T b) noexcept;
        
        //! Adds bivector with multivector
        constexpr Multivector2<T> operator+(const Bivector2<T>& b) const noexcept;
        
        //! Self adds bivector to this multivector, returns a reference to self
        Multivector2<T>& operator+=(const Bivector2<T>& b) noexcept;
        
        //! Adds two multivectors together, returns the result
        constexpr Multivector2<T> operator+(const Multivector2<T>& b) const noexcept;
        
        //! Self adds multivector to this multivector, returns a reference to self
        Multivector2<T>& operator+=(const Multivector2<T>& b) noexcept;
        
        //! Adds vector with multivector
        constexpr Multivector2<T> operator+(const Vector2<T>& b) const noexcept;
        
        //! Self adds vector to this multivector, returns reference to self
        Multivector2<T>& operator+=(const Vector2<T>& b) noexcept;

        //! Subtracts scalar from multivector, returns the result
        constexpr Multivector2<T> operator-(T b) const noexcept;
        
        //! Self subtracts scalar from this multivector, returns reference to self
        Multivector2<T>& operator-=(T b) noexcept;
        
        //! Subtracts bivector from multivector, returns the result
        constexpr Multivector2<T> operator-(const Bivector2<T>& b) const noexcept;
        
        //! Self subtracts bivector from this multivector, returns reference to self
        Multivector2<T>& operator-=(const Bivector2<T>& b) noexcept;
        
        //! Subtracts multivectors, returns the result
        constexpr Multivector2<T> operator-(const Multivector2<T>& b) const noexcept;
        
        //! Self subtracts multivector from this multivector, returns reference to self
        Multivector2<T>& operator-=(const Multivector2<T>& b) noexcept;
        
        //! Subtracts vector from multivector, returns result
        constexpr Multivector2<T> operator-(const Vector2<T>& b) const noexcept;
        
        //! Self subtracts vector from this multivector, returns reference to self
        Multivector2<T>& operator-=(const Vector2<T>& b) noexcept;
        
        //! Scales the multivector by the given amount, returns the result
        template <typename U>
        requires is_arithmetic_v<U>
        constexpr Multivector2<product_t<T,U>> operator*(U b) const noexcept;

        //! Self scales this multivector by the given amount, returns reference to self
        template <typename U>
        requires is_arithmetic_v<U>
        Multivector2<T>& operator*=(U b) noexcept;

        //! Divides multivector by scalar, returns the result
        template <typename U>
        requires is_arithmetic_v<U>
        constexpr Multivector2<quotient_t<T,U>> operator/(U b) const noexcept;

        //! Self divides this multivector by the given amount, returns reference to self
        template <typename U>
        requires is_arithmetic_v<U>
        Multivector2<T>& operator/=(U b) noexcept;

        //! Returns the bivector component
        constexpr Bivector2<T>  bivector() const noexcept;
        
        //! Returns the vector component
        constexpr Vector2<T>    vector() const noexcept;
        
    };

    YQ_IEEE754_1(Multivector2)
    YQ_INTEGER_1(Multivector2)
    YQ_IS_INTEGER_1(Multivector2)

//  --------------------------------------------------------
//  COMPOSITION

    YQ_NAN_1(Multivector2, Multivector2<T>(NAN))
    YQ_ZERO_1(Multivector2, Multivector2<T>(ZERO))

//  --------------------------------------------------------
//  GETTERS

    //! Extracts the bivector part
    template <typename T>
    constexpr Bivector2<T> bivector(const Multivector2<T>& a) noexcept;

    //! Extracts the vector part
    template <typename T>
    constexpr Vector2<T> vector(const Multivector2<T>& a) noexcept;

//  --------------------------------------------------------
//  BASIC FUNCTIONS
    
    YQ_IS_NAN_1(Multivector2, is_nan(v.a) || is_nan(v.x) || is_nan(v.y) || is_nan(v.xy))
    YQ_IS_FINITE_1(Multivector2, is_finite(v.a) && is_finite(v.x) && is_finite(v.y) && is_finite(v.xy))


//  --------------------------------------------------------
//  --------------------------------------------------------

    //! Adds scalar with multivector, returns the result
    template <typename T>
    constexpr Multivector2<T> operator+(T a, const Multivector2<T>& b) noexcept;


    //! Subtracts multivector from scalar, returns the result
    template <typename T>
    constexpr Multivector2<T> operator-(T a, const Multivector2<T>& b) noexcept;


    //! Multiplies scalar with multivector, returns the result
    template <typename T, typename U>
    requires is_arithmetic_v<U>
    constexpr Multivector2<product_t<T,U>> operator*(T a, const Multivector2<U>&b) noexcept;

}

YQ_TYPE_DECLARE(Multivector2D)
YQ_TYPE_DECLARE(Multivector2F)
