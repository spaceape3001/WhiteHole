////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "StdError.hpp"
#include <iostream>

namespace yq::stream {
    StdError::StdError() : StdStream(std::cerr)
    {
    }
    
    StdError::~StdError()
    {
    }
}