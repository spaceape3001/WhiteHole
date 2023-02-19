////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {

    /*! \brief Simple structure for 4-dimensional data

        No math, simple data storage.
    */
    template <typename T>
    struct Data4 {
        T   x, y, z, w;
        constexpr bool operator==(const Data4&) const noexcept = default;
    };
}
