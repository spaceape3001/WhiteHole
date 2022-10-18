////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <math/preamble.hpp>

namespace yq {

    /*! \brief Store data for corners of 3D box
    */
    template <typename T>
    struct AxCorners3 {
        using component_type    = T;
    
        T   lll;
        T   llh;
        T   lhl;
        T   lhh;
        T   hll;
        T   hlh;
        T   hhl;
        T   hhh;
        
        bool operator==(const AxCorners3&) const noexcept = default;
    };
}
