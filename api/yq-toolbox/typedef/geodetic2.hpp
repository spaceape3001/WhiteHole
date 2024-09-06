////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/unit/declare.hpp>

namespace yq {
    template <typename A> struct Geodetic2;
        
    using Geodetic2R    = Geodetic2<unit::Radian>;
    using Geodetic2D    = Geodetic2<unit::Degree>;
}
