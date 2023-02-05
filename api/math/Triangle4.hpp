////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <math/preamble.hpp>
#include <math/AxBox4.hpp>
#include <math/Vector4.hpp>
#include <math/TriangleData.hpp>

namespace yq {

    /*! \brief 3D triangle
    */
    template <typename T>
    struct Triangle4 {
        //! Capture the template parameter
        using component_type    = T;
    
        Vector4<T>   a, b, c;

        constexpr Triangle4() noexcept = default;
        constexpr Triangle4(const Vector4<T>& _a, const Vector4<T>& _b, const Vector4<T>& _c) noexcept : a(_a), b(_b), c(_c) {}
        constexpr Triangle4(const Segment4<T>&, const Vector4<T>& c) noexcept;
        constexpr Triangle4(all_t, const Vector4<T>& v) noexcept : a(v), b(v), c(v) {}
        consteval Triangle4(nan_t) noexcept : Triangle4(ALL, Vector4<T>(NAN)) {}
        consteval Triangle4(zero_t) noexcept : Triangle4(ALL, Vector4<T>(ZERO)) {}
        
        //! Defaulted equality operator
        constexpr bool operator==(const Triangle4&) const noexcept = default;
        
        //! Implicit conversion to triangle data
        constexpr operator TriangleData<Vector4<T>> () const noexcept;

        constexpr Triangle4 operator+() const noexcept;
        constexpr Triangle4 operator-() const noexcept;
        
        constexpr Triangle4 operator+(const Vector4<T>&) const noexcept;
        Triangle4& operator+=(const Vector4<T>&) noexcept;
        constexpr Triangle4 operator-(const Vector4<T>&) const noexcept;
        Triangle4& operator-=(const Vector4<T>&) noexcept;
        
        template <typename U>
        requires trait::is_arithmetic_v<U>
        constexpr Triangle4<trait::product_t<T,U>> operator*(U) const noexcept;
        
        template <typename U>
        requires (trait::is_arithmetic_v<U> && trait::self_mul_v<T,U>)
        Triangle4& operator*=(U) noexcept;

        template <typename U>
        Triangle2<trait::product_t<T,U>>   operator*(const Tensor42<U>&) const noexcept;

        template <typename U>
        Triangle3<trait::product_t<T,U>>   operator*(const Tensor43<U>&) const noexcept;

        template <typename U>
        Triangle4<trait::product_t<T,U>>   operator*(const Tensor44<U>&) const noexcept;

        template <typename U>
        requires trait::self_mul_v<T,U>
        Triangle4&   operator*=(const Tensor44<U>&) noexcept;

        template <typename U>
        requires trait::is_arithmetic_v<U>
        constexpr Triangle4<trait::quotient_t<T,U>> operator/(U) const noexcept;

        template <typename U>
        requires (trait::is_arithmetic_v<U> && trait::self_div_v<T,U>)
        Triangle4& operator/=(U) noexcept;
        
        /*! \brief Bounding box for this triangle
        */
        constexpr AxBox4<T>   bounds() const noexcept;

        //! Edge opposite the "A" vertex
        constexpr Segment4<T>   edge_a() const noexcept;
        constexpr T             edge_a_length() const noexcept;
        constexpr trait::square_t<T>   edge_a_length²() const noexcept;

        //! Edge opposite the "B" vertex
        constexpr Segment4<T>   edge_b() const noexcept;
        constexpr T             edge_b_length() const noexcept;
        constexpr trait::square_t<T>   edge_b_length²() const noexcept;

        //! Edge opposite the "C" vertex
        constexpr Segment4<T>   edge_c() const noexcept;
        constexpr T             edge_c_length() const noexcept;
        constexpr trait::square_t<T>   edge_c_length²() const noexcept;
        
        //! Perimeter of this triangel
        //! \note Might not be reliable for non-floating point types
        T       perimeter() const;
    };

    YQ_IEEE754_1(Triangle4)

//  --------------------------------------------------------
//  COMPOSITION

    /*! \brief Create a triangle from three points */
    template <typename T>
    Triangle4<T>    triangle(const Vector4<T>& a, const Vector4<T>& b, const Vector4<T>& c)
    {
        return { a, b, c };
    }

    YQ_NAN_1(Triangle4, Triangle4<T>(NAN))
    YQ_ZERO_1(Triangle4, Triangle4<T>(ZERO))

//  --------------------------------------------------------
//  --------------------------------------------------------


    YQ_IS_FINITE_1(Triangle4, is_finite(v.a) && is_finite(v.b) && is_finite(v.c))
    YQ_IS_NAN_1(Triangle4, is_nan(v.a) || is_nan(v.b) || is_nan(v.c) )

    template <typename T, typename U>
    requires trait::is_arithmetic_v<T>
    constexpr Triangle4<trait::product_t<T,U>> operator*(T lhs, const Triangle4<U>& rhs) noexcept;

    /*! \brief Creates an axially aligned bounding box from the three triangle vertices */
    template <typename T>
    constexpr AxBox4<T>   aabb(const Triangle4<T>& tri) noexcept;

    /*! \brief Computes the perimeter of the triangle
    */
    template <typename T>
    T       perimeter(const Triangle4<T>& tri);

}

YQ_TYPE_DECLARE(yq::Triangle4D)
YQ_TYPE_DECLARE(yq::Triangle4F)
YQ_TYPE_DECLARE(yq::Triangle4I)
YQ_TYPE_DECLARE(yq::Triangle4U)

