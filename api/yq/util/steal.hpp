////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    template <typename T>
    void    steal(T*& ptr, T*& other)
    {
        ptr     = other;
        other   = nullptr;
    }
}