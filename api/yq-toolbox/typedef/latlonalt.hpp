////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/unit/declare.hpp>

namespace yq {
    template <typename, typename> struct LatLonAlt;
    using LLH   = LatLonAlt<unit::Radian,double>;
    using LLM   = LatLonAlt<unit::Radian,unit::Meter>;
}