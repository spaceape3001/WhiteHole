////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <basic/meta/ArgInfo.hpp>

namespace yq {
    ArgInfo::ArgInfo(std::string_view zName, const std::source_location& sl, const Meta&t, Meta*par) : Meta(zName, par, sl), m_type(t) 
    {
        m_flags |= ARG;
    }
}
