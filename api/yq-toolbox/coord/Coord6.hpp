////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/typedef/coord6.hpp>

#include <yq-toolbox/keywords.hpp>
#include <yq-toolbox/meta/InfoBinder.hpp>
#include <yq-toolbox/trait/has_is_finite.hpp>
#include <yq-toolbox/trait/has_nan.hpp>
#include <yq-toolbox/trait/has_zero.hpp>
#include <yq-toolbox/trait/is_arithmetic.hpp>
#include <yq-toolbox/trait/product.hpp>
#include <yq-toolbox/trait/quotient.hpp>
#include <yq-toolbox/trait/self_divide.hpp>
#include <yq-toolbox/trait/self_multiply.hpp>

namespace log4cpp { class CategoryStream; }

namespace yq {
    class Stream;

    /*! \brief Six dimensional coordinate
    
        This is expanded in six diemnsions for the six-dimensional coordinate.
    */
    template <typename T>
    struct Coord<T,6> {
        //! Component Type
        using component_type    = T;
        
        //! Number of dimensions
        static constexpr const uint8_t  DIMS    = 6;

        //! Coordinate in I
        T   i{};

        //! Coordinate in J
        T   j{};

        //! Coordinate in K
        T   k{};

        //! Coordinate in L
        T   l{};

        //! Coordinate in M
        T   m{};
        
        //! Coordinate in N
        T   n{};
        
        //! Default constructor
        constexpr Coord() noexcept = default;

        //! Component wise constructor
        constexpr Coord(T _i, T _j, T _k, T _l, T _m, T _n) noexcept : 
            i(_i), j(_j), k(_k), l(_l), m(_m), n(_n) {}

        //! Construct all components to same value
        constexpr Coord(all_t, T _v) noexcept : Coord<T,6>(_v, _v, _v, _v, _v, _v) {}

        //! Zero initializing constructor
        constexpr Coord(zero_t) noexcept : Coord<T,6>(ALL, zero_v<T>) {}
        
        //! Defaulted equality  operator
        constexpr bool operator==(const Coord&) const noexcept = default;
        
        //! Conversion operator to other 6-dimensional coordinates
        template <typename U>
        requires (!std::is_same_v<T,U>)
        explicit constexpr operator Coord<U,6>() const noexcept
        {
            return { (U) i, (U) j, (U) k, (U) l, (U) m, (U) n };
        }
        
        //! Allows for uniform coordinate assignments.
        Coord& operator=(T v)
        {
            i = j = k = l = m = n = v;
            return *this;
        }

        constexpr Coord operator+() const noexcept;
        constexpr Coord operator-() const noexcept;
        constexpr Coord operator+(const Coord& b) const noexcept;
        constexpr Coord operator-(const Coord& b) const noexcept;

        Coord& operator+=(const Coord&) noexcept;
        Coord& operator-=(const Coord&) noexcept;

        //! Scales the coordinate
        template <typename U>
            requires is_arithmetic_v<U>
        constexpr Coord6<product_t<T,U>> operator*(U b) const noexcept;
        
        //! Self-scale the coordinate
        template <typename U>
            requires (is_arithmetic_v<U> && self_multiply_v<T,U>)
        Coord& operator*=(U b) noexcept;

        //! Multiplies two coordinates together, term by term
        template <typename U>
        constexpr Coord6<product_t<T,U>> operator*(const Coord6<U>& b) const noexcept;
        
        //! Self-Multiplies left coordinate with right, term by term
        template <typename U>
            requires self_multiply_v<T,U>
        Coord& operator*=(const Coord6<U>& b) noexcept;

        //! Reduces the cooordinate, returns result
        template <typename U>
            requires is_arithmetic_v<U>
        constexpr Coord6<quotient_t<T,U>> operator/(U b) const noexcept;

        //! Reduces the cooordinate in place, returns result
        template <typename U>
            requires (is_arithmetic_v<U> && self_divide_v<T,U>)
        Coord& operator/=(U b) noexcept;

        //! Divides two coordinates, term by term
        template <typename U>
        constexpr Coord6<quotient_t<T,U>> operator/(const Coord6<U>& b) const noexcept;

        //! Self divides left coordinate by right
        template <typename U>
            requires self_divide_v<T,U>
        Coord& operator/=(const Coord6<U>& b) noexcept;
        
        template <typename S>
        S&  stream(S&) const;
    };

    YQ_NAN_1(Coord6, Coord6<T>(ALL, nan_v<T>))
    YQ_IS_NAN_1(Coord6, is_nan(v.i) || is_nan(v.j) || is_nan(v.k) || is_nan(v.l) || is_nan(v.m) || is_nan(v.n))
    YQ_IS_FINITE_1(Coord6, is_finite(v.i) && is_finite(v.j) && is_finite(v.k) && is_finite(v.l) && is_finite(v.m) && is_finite(v.n))
    YQ_ZERO_1(Coord6, Coord6<T>( ZERO ))

    //  --------------------------------------------------------
    //  COMPOSITION

    /*! \brief Composes a six dimensional coordinate from arguments */
    template <typename T>
    constexpr Coord6<T>    coord(T i, std::type_identity_t<T> j, std::type_identity_t<T> k, std::type_identity_t<T> l, std::type_identity_t<T> m, std::type_identity_t<T> n) noexcept
    {
        return { i, j, k, l, m, n };
    }
    
    /*! \brief Construct a uniform 6-dimensional coordinate */
    template <typename T>
    constexpr Coord6<T>    coord6(T i)
    {
        return { i, i, i, i, i, i };
    }


    //  --------------------------------------------------------
    //  BASIC FUNCTIONS

    /*! \brief Max of two coordinates, done by element */
    template <typename T>
    constexpr Coord6<T> max(const Coord6<T>&a, const Coord6<T>& b);

    /*! \brief Min of two coordinates, done by element */
    template <typename T>
    constexpr Coord6<T> min(const Coord6<T>&a, const Coord6<T>& b);

    /*! \brief Product of the components */
    template <typename T>
    constexpr auto product(const Coord6<T>& a);

    /*! \brief Sum of the components */
    template <typename T>
    constexpr T sum(const Coord6<T>& a);
    

    //  --------------------------------------------------------

    //! Scale the coordinate
    template <typename T, typename U>
        requires is_arithmetic_v<T>
    constexpr Coord6<product_t<T,U>> operator*(T a, const Coord6<U>&b);
    
    //! Helper to stream out a coordinate
    template <typename T>
    Stream& operator<<(Stream&, const Coord6<T>&);

    //! Helper to log out a coordinate
    template <typename T>
    log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&, const Coord6<T>&);
}

YQ_TYPE_DECLARE(yq::Coord6D);
YQ_TYPE_DECLARE(yq::Coord6F);
YQ_TYPE_DECLARE(yq::Coord6I);
YQ_TYPE_DECLARE(yq::Coord6U);
YQ_TYPE_DECLARE(yq::Coord6Z);
