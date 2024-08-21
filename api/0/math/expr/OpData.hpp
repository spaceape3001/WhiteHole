////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/math/expr/preamble.hpp>
#include <0/math/expr/SymCategory.hpp>
#include <0/math/expr/SymKind.hpp>

namespace yq::expr {
    struct OpData {
        string_view_t       text;
        Operator            code        = Operator::None;
        OperatorType        type        = OperatorType::None;
        SymCategory		    category	= SymCategory::None;
        SymKind			    kind		= SymKind::None;
        string_view_t       other;
        uint8_t             priority    = 0;
        uint8_t             args        = 0;
        bool				left		= false;
        bool				right		= false;
        bool                self        = false;
    };

}
