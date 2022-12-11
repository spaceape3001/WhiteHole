////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <math/preamble.hpp>
#include <math/Vector2.hpp>
#include <math/Bivector2.hpp>

namespace yq {

    /*! \brief Two dimensional multivector
    */
    template <typename T>
    struct Multivector2 {

        //! Captures the template parameter
        using component_type    = T;

        //! Scalar
        unity_t<T>      a;
        
        //! X (vector component)
        T               x;
        
        //! Y (vector component)
        T               y;
        
        //! XY (bivector component)
        square_t<T>     xy;
        
        //! Defaulted equality operator
        constexpr bool operator==(const Multivector2&) const noexcept = default;
    };

    YQ_IEEE754_1(Multivector2)

//  --------------------------------------------------------
//  COMPOSITION

    YQ_NAN_1(Multivector2, Multivector2<T>{nan_v<unity_t<T>>, nan_v<T>, nan_v<T>, nan_v<square_t<T>>})
    YQ_ZERO_1(Multivector2, Multivector2<T>{zero_v<unity_t<T>>, zero_v<T>, zero_v<T>, zero_v<square_t<T>>})

//  --------------------------------------------------------
//  GETTERS

    //! Extracts the bivector part
    template <typename T>
    constexpr Bivector2<T> bivector(const Multivector2<T>& a) noexcept
    {
        return { a.xy };
    }

    //! Extracts the vector part
    template <typename T>
    constexpr Vector2<T> vector(const Multivector2<T>& a) noexcept
    {
        return { a.x, a.y };
    }

//  --------------------------------------------------------
//  BASIC FUNCTIONS
    
    YQ_IS_NAN_1(Multivector2, is_nan(v.a) || is_nan(v.x) || is_nan(v.y) || is_nan(v.xy))
    YQ_IS_FINITE_1(Multivector2, is_finite(v.a) && is_finite(v.x) && is_finite(v.y) && is_finite(v.xy))


//  --------------------------------------------------------
//  POSITIVE

    //! Affirmation operator (to complement the negative)
    template <typename T>
    constexpr Multivector2<T> operator+(const Multivector2<T>& a) noexcept
    {
        return a;
    }

//  --------------------------------------------------------
//  NEGATIVE

    //! Negation operatpr
    template <typename T>
    constexpr Multivector2<T> operator-(const Multivector2<T>& a) noexcept
    {
        return {-a.a, -a.x, -a.y, -a.xy};
    }



//  --------------------------------------------------------
//  NORMALIZATION


//  --------------------------------------------------------
//  ADDITION

    //! Adds bivector with multivector
    template <typename T>
    constexpr Multivector2<T> operator+(Bivector2<T> a, const Multivector2<T>& b) noexcept
    {
        return { 
            b.a, 
            b.x, b.y,
            a+b.xy
        };
    }

    //! Adds bivector with scalar
    template <typename T>
    constexpr Multivector2<T> operator+(Bivector2<T> a, unity_t<T>  b) noexcept
    {
        return { 
            b, 
            {}, {},
            a.xy
        };
    }
    
    //! Adds bivector with vector
    template <typename T>
    constexpr Multivector2<T> operator+(Bivector2<T> a, const Vector2<T>& b) noexcept
    {
        return { 
            {}, 
            b.x, b.y, 
            a.xy 
        };
    }

    //! Adds multivector with bivector
    template <typename T>
    constexpr Multivector2<T> operator+(const Multivector2<T>& a, const Bivector2<T>& b) noexcept
    {
        return {
            a.a,
            a.x, a.y,
            a.xy + b.xy
        };
    }

    //! Self-addition, adds right bivector into the left multivector
    template <typename T>
    Multivector2<T>& operator+=(Multivector2<T>& a, const Bivector2<T>& b) noexcept
    {
        a.xy += b.xy;
        return a;
    }

    //! Adds two multivectors together
    template <typename T>
    constexpr Multivector2<T> operator+(const Multivector2<T>& a, const Multivector2<T>&  b) noexcept
    {
        return {
            a.a+b.a,
            a.x+b.x, a.y+b.y,
            a.xy+b.xy
        };
    }

    //! Self-addition, adds right multivector into left multivector
    template <typename T>
    Multivector2<T>& operator+=(Multivector2<T>& a, const Multivector2<T>& b) noexcept
    {
        a.a += b.a;
        a.x += b.x; a.y += b.y; 
        a.xy += b.xy;
        return a;
    }
        
    //! Adds multivector with scalar
    template <typename T>
    constexpr Multivector2<T> operator+(const Multivector2<T>& a, unity_t<T>  b) noexcept
    {
        return {
            a.a+b,
            a.x, a.y,
            a.xy
        };
    }

    //! Self-addition, adds right scalar into left multivector
    template <typename T>
    Multivector2<T>& operator+=(Multivector2<T>& a, unity_t<T>  b) noexcept
    {
        a.a += b;
        return a;
    }

    //! Adds multivector with vector
    template <typename T>
    constexpr Multivector2<T> operator+(const Multivector2<T>& a, const Vector2<T>&  b) noexcept
    {
        return {
            a.a,
            a.x+b.x, a.y+b.y,
            a.xy
        };
    }

    //! Self-addition, adds right vector into left multivector
    template <typename T>
    Multivector2<T>& operator+=(Multivector2<T>& a, const Vector2<T>& b) noexcept
    {
        a.x += b.x; a.y += b.y; 
        return a;
    }

    //! Adds scalar with bivector
    template <typename T>
    constexpr Multivector2<T> operator+(unity_t<T> a, const Bivector2<T>& b) noexcept
    {
        return { 
            a, 
            {}, {},
            b 
        };
    }

    //! Adds scalar with multivector
    template <typename T>
    constexpr Multivector2<T> operator+(unity_t<T> a, const Multivector2<T>& b) noexcept
    {
        return { 
            a+b.a, 
            b.x, b.y, 
            b.xy
        };
    }

    //! Adds scalar with vector
    template <typename T>
    constexpr Multivector2<T> operator+(unity_t<T> a, const Vector2<T>& b) noexcept
    {
        return { 
            a, 
            b.x, b.y, 
            {} 
        };
    }

    //! Adds vector with bivector
    template <typename T>
    constexpr Multivector2<T> operator+(const Vector2<T>& a, const Bivector2<T>& b) noexcept
    {
        return { 
            {}, 
            a.x, a.y, 
            b.xy 
        };
    }

    //! Adds vector with multivector
    template <typename T>
    constexpr Multivector2<T> operator+(const Vector2<T>& a, const Multivector2<T>& b) noexcept
    {
        return { 
            b.a, 
            a.x+b.x, a.y+b.y,
            b.xy
        };
    }

    //! Adds vector with scalar
    template <typename T>
    constexpr Multivector2<T> operator+(const Vector2<T>& a, unity_t<T>  b) noexcept
    {
        return { 
            b, 
            a.x, a.y, 
            {} 
        };
    }



//  --------------------------------------------------------
//  SUBTRACTION

    //! Subtracts multivector from bivector
    template <typename T>
    constexpr Multivector2<T> operator-(Bivector2<T> a, const Multivector2<T>& b) noexcept
    {
        return { 
            -b.a, 
            -b.x, -b.y,
            a-b.xy
        };
    }

    //! Subtracts scalar from bivector
    template <typename T>
    constexpr Multivector2<T> operator-(Bivector2<T> a, unity_t<T> b) noexcept
    {
        return { 
            -b, 
            {}, {},
            a.xy
        };
    }

    //! Subtracts vector from bivector
    template <typename T>
    constexpr Multivector2<T> operator-(Bivector2<T> a, const Vector2<T>& b) noexcept
    {
        return { 
            {}, 
            -b.x, -b.y, 
            a.xy 
        };
    }

    //! Subtracts bivector from multivector
    template <typename T>
    constexpr Multivector2<T> operator-(const Multivector2<T>& a, const Bivector2<T>& b) noexcept
    {
        return {
            a.a,
            a.x, a.y,
            a.xy - b.xy
        };
    }

    //! Self-subtraction, subtracts the right bivector from the left multivector
    template <typename T>
    Multivector2<T>& operator-=(Multivector2<T>& a, const Bivector2<T>& b) noexcept
    {
        a.xy -= b.xy;
        return a;
    }

    //! Subtracts two multivectors
    template <typename T>
    constexpr Multivector2<T> operator-(const Multivector2<T>& a, const Multivector2<T>& b) noexcept
    {
        return {
            a.a-b.a,
            a.x-b.x, a.y-b.y,
            a.xy-b.xy
        };
    }

    //! Self-subtraction, subtracts the right multivector from the left multivector
    template <typename T>
    Multivector2<T>& operator-=(Multivector2<T>& a, const Multivector2<T>& b) noexcept
    {
        a.a -= b.a;
        a.x -= b.x; a.y -= b.y; 
        a.xy -= b.xy;
        return a;
    }
    
    //! Subtracts the scalar from the multivector
    template <typename T>
    constexpr Multivector2<T> operator-(const Multivector2<T>& a, unity_t<T> b) noexcept
    {
        return {
            a.a-b,
            a.x, a.y,
            a.xy
        };
    }

    //! Self-subtraction, subtracts the right scalar from the left multivector
    template <typename T>
    Multivector2<T>& operator-=(Multivector2<T>& a, unity_t<T> b) noexcept
    {
        a.a -= b;
        return a;
    }

    //! Subtracts the vector from the multivector
    template <typename T>
    constexpr Multivector2<T> operator-(const Multivector2<T>& a, const Vector2<T>& b) noexcept
    {
        return {
            a.a,
            a.x-b.x, a.y-b.y,
            a.xy
        };
    }

    //! Self-subtraction, subtracts the right vector from the left multivector
    template <typename T>
    Multivector2<T>& operator-=(Multivector2<T>& a, const Vector2<T>& b) noexcept
    {
        a.x -= b.x; a.y -= b.y; 
        return a;
    }
    
    //! Subtracts bivector from scalar
    template <typename T>
    constexpr Multivector2<T> operator-(unity_t<T> a, const Bivector2<T>& b) noexcept
    {
        return { 
            a, 
            {}, {},
            -b 
        };
    }    

    //! Subtracts multivector from scalar
    template <typename T>
    constexpr Multivector2<T> operator-(unity_t<T> a, const Multivector2<T>& b) noexcept
    {
        return { 
            a-b.a, 
            -b.x, -b.y, 
            -b.xy
        };
    }

    //! Subtracts vector from scalar
    template <typename T>
    constexpr Multivector2<T> operator-(unity_t<T> a, const Vector2<T>& b) noexcept
    {
        return { 
            a, 
            -b.x, -b.y, 
            {} 
        };
    }

    //! Subtracts bivector from vector
    template <typename T>
    constexpr Multivector2<T> operator-(const Vector2<T>& a, const Bivector2<T>& b) noexcept
    {
        return { 
            {}, 
            a.x, a.y, 
            -b.xy 
        };
    }

    //! Subtracts multivector from vector
    template <typename T>
    constexpr Multivector2<T> operator-(const Vector2<T>& a, const Multivector2<T>& b) noexcept
    {
        return { 
            -b.a, 
            a.x-b.x, a.y-b.y,
            -b.xy
        };
    }

    //! Subtracts scalar from vector
    template <typename T>
    constexpr Multivector2<T> operator-(const Vector2<T>& a, unity_t<T> b) noexcept
    {
        return { 
            -b, 
            a.x, a.y, 
            {} 
        };
    }

    
//  --------------------------------------------------------
//  MULTIPLICATION

    //! Scaling multiplication of scalar with multivector
    template <typename T>
    requires std::is_floating_point_v<T>
    constexpr Multivector2<T> operator*(T a, const Multivector2<T>&b) noexcept
    {
        return { 
            a*b.a, 
            a*b.x, a*b.y, 
            a*b.xy 
        };
    }

    //! Scaling multiplication of scalar with multivector
    template <typename T>
    requires std::is_floating_point_v<T>
    constexpr Multivector2<T> operator*(const Multivector2<T>& a, T b) noexcept
    {
        return { 
            a.a*b, 
            a.x*b, a.y*b, 
            a.xy*b 
        };
    }

    //! Self-scalaring multiplying left multivector by right scalar
    template <typename T>
    requires std::is_floating_point_v<T>
    Multivector2<T>& operator*=(Multivector2<T>& a, T b) noexcept
    {
        a.a  *= b;
        a.x  *= b; a.y *= b; 
        a.xy *= b;
        return a;
    }

    //! Geometric product
    //! 
    //! This is the basis to the geometric algebra, multiplying two vectors together.
    template <typename T>
    requires std::is_floating_point_v<T>
    constexpr Multivector2<T>   operator* (const Vector2<T>&a, const Vector2<T>&b) 
    {
        return { a.x*b.x+a.y*b.y, 0., 0., a.x*b.y-a.y*b.x };
    }

//  --------------------------------------------------------
//  DIVISION

    //! Scaling division, reducing the left mulitvector by the right value
    template <typename T>
    requires std::is_floating_point_v<T>
    constexpr Multivector2<T> operator/(const Multivector2<T>& a, T b) noexcept
    {
        return { 
            a.a/b, 
            a.x/b, a.y/b, 
            a.xy/b 
        };
    }

    //! Self-scaling division, reducing the left mulitvector by the right value
    template <typename T>
    requires std::is_floating_point_v<T>
    Multivector2<T>& operator/=(Multivector2<T>& a, T b) noexcept
    {
        a.a  /= b;
        a.x  /= b; a.y /= b; 
        a.xy /= b;
        return a;
    }

    //! Division of left vector by the right
    template <typename T>
    requires std::is_floating_point_v<T>
    constexpr Multivector2<T>   operator/ (const Vector2<T>&a, const Vector2<T>&b) 
    {
        return (a * b) / length2(b);
    }

//  --------------------------------------------------------
//  POWERS

//  --------------------------------------------------------
//  DOT PRODUCT


//  --------------------------------------------------------
//  INNER PRODUCT


//  --------------------------------------------------------
//  OUTER PRODUCT


//  --------------------------------------------------------
//  CROSS PRODUCT


///  --------------------------------------------------------
//  OTIMES PRODUCT

//  --------------------------------------------------------
//  UNIONS

//  --------------------------------------------------------
//  INTERSECTIONS


//  --------------------------------------------------------
//  PROJECTIONS

//  --------------------------------------------------------
//  ADVANCED FUNCTIONS

}

YQ_TYPE_DECLARE(Multivector2D)
YQ_TYPE_DECLARE(Multivector2F)
