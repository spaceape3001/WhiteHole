////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <math/preamble.hpp>
#include <math/Vector4.hpp>

namespace yq {

    /*! \brief Structure for polyline data
    */
    template <typename T>
    struct Polyline4 {
        //! Capture the template parameter
        using component_type    = T;
        
        //! Vertex data
        std::vector<Vector4<T>>     vertex;
        
        constexpr Polyline4() noexcept = default;
        Polyline4(const std::vector<Vector4<T>>&);
        Polyline4(std::vector<Vector4<T>>&&);
        Polyline4(std::initializer_list<Vector4<T>>);
        Polyline4(std::span<const Vector4<T>>);
        
        explicit Polyline4(const Segment4<T>&);

        //! Defaulted equality operator
        constexpr bool operator==(const Polyline4&) const noexcept = default;

        operator PolylineData<Vector4<T>>() const;

        //! Addsa a point to the polyline
        Polyline4&   operator<<(const Vector4<T>& pt);

        //! Compute the bounding box to this polyline
        constexpr AxBox4<T>   bounds() const noexcept;
        
        //! Computes the length of the polyline
        //! \note May be less accurate with non-floating point types
        T       length() const;

        template <typename Pred>
        void    segments(Pred) const;

        std::vector<Segment4<T>>    segments() const;
    };

    /*! \brief Creates a polyline from a box
    */
    template <typename T>
    Polyline4<T> polyline(const AxBox4<T>& ax);

    template <typename T>
    Polyline4<T> polyline(std::span<const Vector4<T>> pts);

    template <typename T>
    Polyline4<T> polyline(std::initializer_list<const Vector4<T>> pts);

    template <typename T>
    Polyline4<T> polyline(std::vector<Vector4<T>>&& pts);

    template <typename T>
    Polyline4<T> polyline(const Segment4<T>&);

    YQ_IEEE754_1(Polyline4)
    YQ_ZERO_1(Polyline4, { })


    /*! \brief Create an axially aligned bounding box from a polyline
    */
    template <typename T>
    AxBox4<T>   aabb(const Polyline4<T>&poly);

    //! Tests that all vertices are finite
    template <typename T>
    bool is_finite(const Polyline4<T>& poly)
    {
        for(auto& v : poly.vertex)
            if(!is_finite(v))
                return false;
        return true;
    }
    
    //! Tests for any vertice that is not-a-number
    template <typename T>
    bool is_nan(const Polyline4<T>& poly)
    {
        for(auto& v : poly.vertex)
            if(is_nan(v))
                return true;
        return false;
    }
    
    template <typename T>
    T       length(const Polyline4<T>& poly);
}

