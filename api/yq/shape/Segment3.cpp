////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Segment3.hpp"

#include <yq/strings.hpp>
#include <yq/core/DelayInit.hpp>
#include <yq/meta/Init.hpp>

#include "Segment3.hxx"

YQ_TYPE_IMPLEMENT(yq::Segment3D)
YQ_TYPE_IMPLEMENT(yq::Segment3F)
YQ_TYPE_IMPLEMENT(yq::Segment3I)
YQ_TYPE_IMPLEMENT(yq::Segment3U)

using namespace yq;

static void reg_segment3()
{
    {
        auto w = writer<Segment3D>();
        w.description("3D Segment in double");
        w.property(szA, &Segment3D::a).description(szA_Segment);
        w.property(szB, &Segment3D::b).description(szB_Segment);
    }

    {
        auto w = writer<Segment3F>();
        w.description("3D Segment in float");
        w.property(szA, &Segment3F::a).description(szA_Segment);
        w.property(szB, &Segment3F::b).description(szB_Segment);
    }

    {
        auto w = writer<Segment3I>();
        w.description("3D Segment in integer");
        w.property(szA, &Segment3I::a).description(szA_Segment);
        w.property(szB, &Segment3I::b).description(szB_Segment);
    }

    {
        auto w = writer<Segment3U>();
        w.description("3D Segment in unsigned integer");
        w.property(szA, &Segment3U::a).description(szA_Segment);
        w.property(szB, &Segment3U::b).description(szB_Segment);
    }
}

YQ_INVOKE(reg_segment3();)
