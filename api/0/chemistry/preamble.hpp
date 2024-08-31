////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/math/preamble.hpp>
#include <0/basic/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::chemistry {
    YQ_ENUM( Phase, ,
        Unknown = 0,
        Solid,
        Liquid,
        Gas,
        Plasma
    )
}

YQ_TYPE_DECLARE(yq::chemistry::Phase)
