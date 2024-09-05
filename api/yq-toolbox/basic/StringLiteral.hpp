////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

// using example
// https://pureprogrammer.org/wp/2021/12/19/using-string-literals-as-c-template-parameters/

#include <algorithm>
#include <string_view>

namespace yq {
    template <size_t N>
    struct StringLiteral {
        char value[N];

        constexpr StringLiteral(const char (&str)[N])
        {
            std::copy_n(str, N, value);
        }
        
        constexpr std::string_view view() const  noexcept
        {
            return std::string_view(value, N);
        }
    };
}
