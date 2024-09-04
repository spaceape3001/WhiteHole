////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/math/unit/declare.hpp>

namespace yq {
    template <typename> struct Vector3;
    
    using Vector3D                  = Vector3<double>;
    using Vector3F                  = Vector3<float>;
    using Vector3I                  = Vector3<int>;
    using Vector3U                  = Vector3<unsigned>;
    using Vector3M                  = Vector3<Meter>;
}