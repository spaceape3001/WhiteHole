////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

/* 
    This is the template IMPLEMENTATION of the axbox4 code.  Include this
    *IF* you need the operator and it's not yet available as explicit 
    template instantiation.  
*/

#include <math/AxBox4.hpp>
#include <math/AxCorners4.hpp>
#include <math/Data4.hpp>
#include <math/Range.hpp>
#include <math/Side.hpp>
#include <math/Size4.hpp>
#include <math/Segment4.hpp>
#include <math/utility.hpp>

namespace yq {
    template <typename T>
    constexpr AxBox4<T>::AxBox4(intersect_t, std::initializer_list<Vector4<T>> ls, std::initializer_list<Vector4<T>> hs) noexcept:
        AxBox4(INTERSECT, span(ls), span(hs))
    {}

    template <typename T>
    constexpr AxBox4<T>::AxBox4(intersect_t, std::span<const Vector4<T>>ls, std::span<const Vector4<T>>hs) noexcept
    {
        if(!ls.empty()){
            lo.x    = std::max_element(ls.begin(), ls.end(), Vector4<T>::less_x) -> x;
            lo.y    = std::max_element(ls.begin(), ls.end(), Vector4<T>::less_y) -> y;
            lo.z    = std::max_element(ls.begin(), ls.end(), Vector4<T>::less_z) -> z;
            lo.w    = std::max_element(ls.begin(), ls.end(), Vector4<T>::less_w) -> w;
        } else {
            lo      = Vector4<T>(ZERO);
        }
        
        if(!hs.empty()){
            hi.x    = std::min_element(hs.begin(), hs.end(), Vector4<T>::less_x) -> x;
            hi.y    = std::min_element(hs.begin(), hs.end(), Vector4<T>::less_y) -> y;
            hi.z    = std::min_element(hs.begin(), hs.end(), Vector4<T>::less_z) -> z;
            hi.w    = std::min_element(hs.begin(), hs.end(), Vector4<T>::less_w) -> w;
        } else {
            hi      = Vector4<T>(ZERO);
        }
    }

    template <typename T>
    constexpr AxBox4<T>::AxBox4(sort_t, const Vector4<T>&a, const Vector4<T>& b) noexcept
    {
        std::tie(lo.x, hi.x)    = std::minmax(a.x, b.x);
        std::tie(lo.y, hi.y)    = std::minmax(a.y, b.y);
        std::tie(lo.z, hi.z)    = std::minmax(a.z, b.z);
        std::tie(lo.w, hi.w)    = std::minmax(a.w, b.w);
    }

    template <typename T>
    constexpr AxBox4<T>::AxBox4(union_t, const Vector4<T>&a, const Vector4<T>& b) noexcept : AxBox4(SORT, a, b) {}

    template <typename T>
    constexpr AxBox4<T>::AxBox4(union_t, std::initializer_list<Vector4<T>> list) noexcept : 
        AxBox4(UNION, span(list)){}

    template <typename T>
    constexpr AxBox4<T>::AxBox4(union_t, std::span<const Vector4<T>> data) noexcept : AxBox4{}
    {
        if(!data.empty()){
            auto [lx, hx] = std::minmax_element(data.begin(), data.end(), Vector4<T>::less_x);
            lo.x = lx->x;
            hi.x = hx->x;

            auto [ly, hy] = std::minmax_element(data.begin(), data.end(), Vector4<T>::less_y);
            lo.y = lx->y;
            hi.y = hx->y;

            auto [lz, hz] = std::minmax_element(data.begin(), data.end(), Vector4<T>::less_z);
            lo.z = lx->z;
            hi.z = hx->z;

            auto [lw, hw] = std::minmax_element(data.begin(), data.end(), Vector4<T>::less_w);
            lo.w = lx->w;
            hi.w = hx->w;
        } else {
            lo = hi = Vector4<T>(ZERO);
        }
    }

    template <typename T>
    constexpr AxBox4<T>::AxBox4(union_t, std::initializer_list<Vector4<T>> ls, std::initializer_list<Vector4<T>> hs) noexcept :
        AxBox4(UNION, span(ls), span(hs)) {}

    template <typename T>
    constexpr AxBox4<T>::AxBox4(union_t, std::span<const Vector4<T>>ls, std::span<const Vector4<T>>hs) noexcept
    {
        if(!ls.empty()){
            lo.x    = std::min_element(ls.begin(), ls.end(), Vector4<T>::less_x) -> x;
            lo.y    = std::min_element(ls.begin(), ls.end(), Vector4<T>::less_y) -> y;
            lo.z    = std::min_element(ls.begin(), ls.end(), Vector4<T>::less_z) -> z;
            lo.w    = std::min_element(ls.begin(), ls.end(), Vector4<T>::less_w) -> w;
        } else {
            lo      = Vector4<T>(ZERO);
        }
        
        if(!hs.empty()){
            hi.x    = std::max_element(hs.begin(), hs.end(), Vector4<T>::less_x) -> x;
            hi.y    = std::max_element(hs.begin(), hs.end(), Vector4<T>::less_y) -> y;
            hi.z    = std::max_element(hs.begin(), hs.end(), Vector4<T>::less_z) -> z;
            hi.w    = std::max_element(hs.begin(), hs.end(), Vector4<T>::less_w) -> w;
        } else {
            hi      = Vector4<T>(ZERO);
        }
    }

    template <typename T>
    constexpr AxBox4<T>::AxBox4(const Segment4<T>&seg) noexcept : AxBox4<T>(seg.bounds()) {}


    template <typename T>
    constexpr AxBox4<T>::AxBox4(const Sphere4<T>& sph) noexcept : AxBox4(sph.bounds()) {}

    template <typename T>
    constexpr AxBox4<T>::AxBox4(const Triangle4<T>&tri) noexcept : AxBox4<T>(tri.bounds()) {}

    template <typename T>
    AxBox4<T>  AxBox4<T>::operator+() const noexcept
    {
        return *this;
    }

    template <typename T>
    AxBox4<T>  AxBox4<T>::operator-() const noexcept
    {
        return AxBox4<T>(-hi, -lo);
    }

    template <typename T>
    AxBox4<T>  AxBox4<T>::operator+(const Vector4<T>&b) const noexcept
    {
        return AxBox4<T>(lo+b, hi+b);
    }

    template <typename T>
    AxBox4<T>& AxBox4<T>::operator+=(const Vector4<T>&b) noexcept
    {
        lo += b;
        hi += b;
        return *this;
    }

    template <typename T>
    AxBox4<T>  AxBox4<T>::operator-(const Vector4<T>&b) const noexcept
    {
        return AxBox4<T>(lo-b, hi-b);
    }

    template <typename T>
    AxBox4<T>& AxBox4<T>::operator-=(const Vector4<T>&b) noexcept
    {
        lo -= b;
        hi -= b;
        return *this;
    }

    template <typename T>
        template <typename U>
    requires is_arithmetic_v<U>
    AxBox4<product_t<T,U>> AxBox4<T>::operator*(U b) const noexcept
    {
        if(b >= zero_v<U>)
            return AxBox4<product_t<T,U>>(lo*b,hi*b);
        else
            return AxBox4<product_t<T,U>>(hi*b,lo*b);
    }

    template <typename T>
        template <typename U>
    requires (is_arithmetic_v<U> && self_mul_v<T,U>)
    AxBox4<T>& AxBox4<T>::operator*=(U b) noexcept
    {
        *this = *this * b;
        return *this;
    }
        
    template <typename T>
        template <typename U>
    requires is_arithmetic_v<U>
    AxBox4<quotient_t<T,U>> AxBox4<T>::operator/(U b) const noexcept
    {
        if(b >= zero_v<U>)
            return AxBox4<quotient_t<T,U>>(lo/b,hi/b);
        else
            return AxBox4<quotient_t<T,U>>(hi/b,lo/b);
    }

    template <typename T>
        template <typename U>
    requires (is_arithmetic_v<U> && self_div_v<T,U>)
    AxBox4<T>& AxBox4<T>::operator/=(U b) noexcept
    {
        *this = *this / b;
        return *this;
    }
        

    template <typename T>
    constexpr AxBox4<T> AxBox4<T>::operator|(const AxBox4<T>&b) const noexcept
    {
        return AxBox4(UNION, {lo, hi, b.lo, b.hi});
    }

    template <typename T>
    constexpr AxBox4<T> AxBox4<T>::operator|(const Vector4<T>&b) const noexcept
    {
        return AxBox4(UNION, {lo, hi, b});
    }

    template <typename T>
    AxBox4<T>& AxBox4<T>::operator|=(const AxBox4& b) noexcept
    {
        *this   = *this | b;
        return *this;
    }

    template <typename T>
    AxBox4<T>& AxBox4<T>::operator|=(const Vector4<T>& b) noexcept
    {
        *this   = *this | b;
        return *this;
    }

    template <typename T>
    constexpr AxBox4<T> AxBox4<T>::operator&(const AxBox4<T>&b) const noexcept
    {
        return AxBox4(INTERSECT, {lo, b.lo}, {hi, b.hi});
    }

    template <typename T>
    AxBox4<T>& AxBox4<T>::operator&=(const AxBox4& b) noexcept
    {
        *this = *this & b;
        return *this;
    }

    template <typename T>
    constexpr Vector4<T>      AxBox4<T>::center() const noexcept
    {
        if constexpr (is_floating_point_v<T>)
            return ieee754_t<T>(0.5)*(lo+hi);
        if constexpr (std::is_integral_v<T>)
            return (lo+hi) / T(2);
        return {};
    }

    template <typename T>
    constexpr Data4<Side>       AxBox4<T>::classify(const Vector4<T>&v) const noexcept
    {
        return Data4<Side>( classify_x(v.x), classify_y(v.y), classify_z(v.z), classify_w(v.w) );
    }
    
    template <typename T>
    constexpr Side              AxBox4<T>::classify_w(T v) const noexcept
    {
        return _classify(v, lo.w, hi.w);
    }

    template <typename T>
    constexpr Side              AxBox4<T>::classify_w(const Vector4<T>&v) const noexcept
    {
        return classify_w(v.w);
    }

    template <typename T>
    constexpr Side              AxBox4<T>::classify_x(T v) const noexcept
    {
        return _classify(v, lo.x, hi.x);
    }

    template <typename T>
    constexpr Side              AxBox4<T>::classify_x(const Vector4<T>&v) const noexcept
    {
        return classify_x(v.x);
    }

    template <typename T>
    constexpr Side              AxBox4<T>::classify_y(T v) const noexcept
    {
        return _classify(v, lo.y, hi.y);
    }

    template <typename T>
    constexpr Side              AxBox4<T>::classify_y(const Vector4<T>&v) const noexcept
    {
        return classify_y(v.y);
    }

    template <typename T>
    constexpr Side              AxBox4<T>::classify_z(T v) const noexcept
    {
        return _classify(v, lo.z, hi.z);
    }

    template <typename T>
    constexpr Side              AxBox4<T>::classify_z(const Vector4<T>&v) const noexcept
    {
        return classify_z(v.z);
    }


    template <typename T>
    constexpr bool AxBox4<T>::contains (const Vector4<T>& pt) const noexcept
    {
        return (all(lo) <= pt) && (all(pt) <= hi);
    }

    template <typename T>
    constexpr AxCorners4<Vector4<T>>  AxBox4<T>::corners() const noexcept
    {
        return AxCorners4<Vector4<T>>(
            llll(),
            lllh(),
            llhl(),
            llhh(),
            lhll(),
            lhlh(),
            lhhl(),
            lhhh(),
            
            hlll(),
            hllh(),
            hlhl(),
            hlhh(),
            hhll(),
            hhlh(),
            hhhl(),
            hhhh()
        );
    }

    template <typename T>
    constexpr AxCorners4<Vector4<T>>    AxBox4<T>::corners(T adjust) const noexcept
    {
        return inflate(adjust).corners();
    }

    template <typename T>
    T                       AxBox4<T>::distance(const Vector4<T>&v) const
    {
        if constexpr ( has_sqrt_v<T> )
            return sqrt(distance²(v));
        return zero_v<T>;
    }
    
    template <typename T>
    constexpr square_t<T>   AxBox4<T>::distance²(const Vector4<T>&v) const noexcept
    {
        return 
            (_gap(v.x, lo.x, hi.x)^²) +
            (_gap(v.y, lo.y, hi.y)^²) +
            (_gap(v.z, lo.z, hi.z)^²) +
            (_gap(v.w, lo.w, hi.w)^²)
        ;
    }

    template <typename T>
    constexpr bool AxBox4<T>::eclipses(const AxBox4<T>& b) const noexcept
    {
        return (all(lo) <= b.lo) && (all(b.hi) <= hi);
    }
    
    template <typename T>
    constexpr AxBox4<T> AxBox4<T>::fixed() const noexcept
    {
        return AxBox4(UNION, lo, hi);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hhhh() const noexcept
    {
        return hi;
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hhhh(T adjust) const noexcept
    {
        return Vector4<T>(hi.x+adjust,hi.y+adjust,hi.z+adjust,hi.w+adjust);
    }
    
    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hhhl() const noexcept
    {
        return Vector4<T>(hi.x,hi.y,hi.z,lo.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hhhl(T adjust) const noexcept
    {
        return Vector4<T>(hi.x+adjust,hi.y+adjust,hi.z+adjust,lo.w-adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hhlh() const noexcept
    {
        return Vector4<T>(hi.x,hi.y,lo.z,hi.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hhlh(T adjust) const noexcept
    {
        return Vector4<T>(hi.x+adjust,hi.y+adjust,lo.z-adjust,hi.w+adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hhll() const noexcept
    {
        return Vector4<T>(hi.x,hi.y,lo.z,lo.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hhll(T adjust) const noexcept
    {
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hlhh() const noexcept
    {
        return Vector4<T>(hi.x,lo.y,hi.z,hi.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hlhh(T adjust) const noexcept
    {
        return Vector4<T>(hi.x+adjust,lo.y-adjust,hi.z+adjust,hi.w+adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hlhl() const noexcept
    {
        return Vector4<T>(hi.x,lo.y,hi.z,lo.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hlhl(T adjust) const noexcept
    {
        return Vector4<T>(hi.x+adjust,lo.y-adjust,hi.z+adjust,lo.w-adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hllh() const noexcept
    {
        return Vector4<T>(hi.x,lo.y,lo.z,hi.w);
    }
    

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hllh(T adjust) const noexcept
    {
        return Vector4<T>(hi.x+adjust,lo.y-adjust,lo.z-adjust,hi.w+adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hlll() const noexcept
    {
        return Vector4<T>(hi.x,lo.y,lo.z,lo.w);
    }
    
    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::hlll(T adjust) const noexcept
    {
        return Vector4<T>(hi.x+adjust,lo.y-adjust,lo.z-adjust,lo.w-adjust);
    }

    template <typename T>
    constexpr fourth_t<T> AxBox4<T>::hypervolume() const noexcept
    {
        return (hi-lo).cproduct();
    }

    template <typename T>
    constexpr fourth_t<T> AxBox4<T>::hypervolume(guard_t) const noexcept
    {
        return abs(hypervolume());
    }

    template <typename T>
    constexpr AxBox4<T>    AxBox4<T>::inflate(T d) const noexcept
    {
        return AxBox4(all(lo) - d, all(hi) + d);
    }

    template <typename T>
    constexpr AxBox4<T>    AxBox4<T>::inflate(guard_t, T d) const noexcept
    {
        AxBox4  bx  = fixed();
        return bx.inflate(std::max(d, bx.min_inflate()));
    }

    template <typename T>
    constexpr bool    AxBox4<T>::is_valid() const noexcept
    {
        return all(lo) <= hi;
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::lhhh() const noexcept
    {
        return Vector4<T>(lo.x,hi.y,hi.z,hi.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::lhhh(T adjust) const noexcept
    {
        return Vector4<T>(lo.x-adjust,hi.y+adjust,hi.z+adjust,hi.w+adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::lhhl() const noexcept
    {
        return Vector4<T>(lo.x,hi.y,hi.z,lo.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::lhhl(T adjust) const noexcept
    {
        return Vector4<T>(lo.x-adjust,hi.y+adjust,hi.z+adjust,lo.w-adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::lhlh() const noexcept
    {
        return Vector4<T>(lo.x,hi.y,lo.z,hi.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::lhlh(T adjust) const noexcept
    {
        return Vector4<T>(lo.x-adjust,hi.y+adjust,lo.z-adjust,hi.w+adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::lhll() const noexcept
    {
        return Vector4<T>(lo.x,hi.y,lo.z,lo.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::lhll(T adjust) const noexcept
    {
        return Vector4<T>(lo.x-adjust,hi.y+adjust,lo.z-adjust,lo.w-adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::llhh() const noexcept
    {
        return Vector4<T>(lo.x,lo.y,hi.z,hi.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::llhh(T adjust) const noexcept
    {
        return Vector4<T>(lo.x-adjust,lo.y-adjust,hi.z+adjust,hi.w+adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::llhl() const noexcept
    {
        return Vector4<T>(lo.x,lo.y,hi.z,lo.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::llhl(T adjust) const noexcept
    {
        return Vector4<T>(lo.x-adjust,lo.y-adjust,hi.z+adjust,lo.w-adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::lllh() const noexcept
    {
        return Vector4<T>(lo.x,lo.y,lo.z,hi.w);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::lllh(T adjust) const noexcept
    {
        return Vector4<T>(lo.x-adjust,lo.y-adjust,lo.z-adjust,hi.w+adjust);
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::llll() const noexcept
    {
        return lo;
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::llll(T adjust) const noexcept
    {
        return Vector4<T>(lo.x-adjust,lo.y-adjust,lo.z-adjust,lo.w-adjust);
    }

    template <typename T>
    constexpr T AxBox4<T>::min_inflate() const noexcept
    {
        return -midspan(span().cmin());
    }

    template <typename T>
    constexpr bool AxBox4<T>::overlaps(const AxBox4<T>& b) const noexcept
    {
        return (all(lo) <= b.hi) && (all(b.lo) <= hi);
    }

    template <typename T>
    template <typename>
    requires std::is_floating_point_v<T>
    constexpr Vector4<T>   AxBox4<T>::project(const Vector4<T>& v) const noexcept
    {
        return (one_v<Vector4<T>>-v).emul(lo) + v.emul(hi);
    }

    template <typename T>
    constexpr Size4<T> AxBox4<T>::size() const noexcept 
    {
        auto s = span();
        return Size4<T>{ s.x, s.y, s.z, s.w  }; 
    }

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::span() const noexcept
    {
        return hi - lo;
    }
    

    template <typename T>
    constexpr Vector4<T>    AxBox4<T>::span(guard_t) const noexcept
    {
        return span().eabs();
    }
    
    template <typename T>
    template <typename>
    requires std::is_floating_point_v<T>
    constexpr Vector4<T>   AxBox4<T>::unproject(const Vector4<T>& v) const noexcept
    {
        return div_elem(v-lo, hi-lo);
    }

    template <typename T>
    constexpr bool          AxBox4<T>::valid() const noexcept 
    {
        return all(lo) <= hi;
    }

    template <typename T>
    constexpr Range<T>  AxBox4<T>::x_range() const noexcept
    {
        return range(lo.x, hi.x);
    }

    template <typename T>
    constexpr Range<T>  AxBox4<T>::y_range() const noexcept
    {
        return range(lo.y, hi.y);
    }

    template <typename T>
    constexpr Range<T>  AxBox4<T>::z_range() const noexcept
    {
        return range(lo.z, hi.z);
    }

    template <typename T>
    constexpr Range<T>  AxBox4<T>::w_range() const noexcept
    {
        return range(lo.w, hi.w);
    }
    
    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    template <typename T, typename U>
    requires is_arithmetic_v<T>
    constexpr AxBox4<product_t<T,U>> operator*(T a, const AxBox4<U>& b) noexcept
    {
        if(a >= zero_v<T>)
            return AxBox4<product_t<T,U>>(a*b.lo, a*b.hi);
        else
            return AxBox4<product_t<T,U>>(a*b.hi, a*b.lo);
    }

    template <typename T>
    constexpr AxBox4<T> aabb(const Vector4<T>& a) noexcept
    {
        return AxBox4<T>(a);
    }

    template <typename T>
    constexpr AxBox4<T> aabb(const Vector4<T>& a, const Vector4<T>& b) noexcept
    {
        return AxBox4<T>(UNION,a,b);
    }

    template <typename T>
    AxBox4<T> aabb(const std::vector<Vector4<T>>& vals)
    {
        switch(vals.size()){
        case 0:
            return AxBox4<T>(ZERO);
        case 1:
            return AxBox4<T>(vals[0]);
        case 2:
            return AxBox4<T>(UNION, vals[0],vals[1]);
        default:
            break;
        }

        return AxBox4<T>(UNION, vals);
    }

    template <typename T>
    constexpr Vector4<T>      center(const AxBox4<T>& box) noexcept
    {
        return box.center();
    }

    template <typename T>
    Vector4<T>  centroid(const AxBox4<T>& box)
    {
        return box.center();
    }

    template <typename T>
    constexpr fourth_t<T>   hypervolume(const AxBox4<T>& box) noexcept
    {
        return box.hypervolume();
    }


    template <typename T>
    constexpr bool    is_valid(const AxBox4<T>& box) noexcept
    {
        return box.is_valid();
    }

    template <typename T>
    constexpr Vector4<T>    span(const AxBox4<T>&box) noexcept
    {
        return box.span();
    }
}
