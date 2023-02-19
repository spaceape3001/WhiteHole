////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {

    /*! \brief Simple structure for 3-dimensional data

        No math, simple data storage.
    */
    template <typename T>
    struct Data3 {
        T   x, y, z;
        constexpr bool operator==(const Data3&) const noexcept = default;
    };
}
