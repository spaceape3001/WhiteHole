////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "OnRequest.hpp"
#include <yq/core/DelayInit.hpp>
#include <yq/post/TriggerInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::post::OnRequest)

namespace yq::post {

    OnRequest::OnRequest(const RequestInfo& cInfo, const Param& p) : Trigger(p), m_info(cInfo)
    {
    }
    
    OnRequest::~OnRequest()
    {
    }
    
    bool OnRequest::accept(const Request& cmd) const
    {
        const RequestInfo& cInfo    = cmd.metaInfo();
        return (&cInfo == &m_info) || cInfo.is_base(m_info);
    }
    
    static void reg_on_request()
    {
        auto w = writer<OnRequest>();
        w.description("Trigger for a particular request class");
    }
    
    YQ_INVOKE(reg_on_request();)
}