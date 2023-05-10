////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <meta/MetaWriter.hpp>
#include <basic/Any.hpp>
#include <cassert>

namespace yq {        
    
    Meta::Writer::Writer(Meta* myMeta) : m_meta(myMeta) 
    {
        assert(thread_safe_write());
    }


    Meta::Writer&     Meta::Writer::alias(std::string_view zAlias)
    {
        if(m_meta)
            m_meta -> m_aliases << zAlias;
        return *this;
    }
    
    Meta::Writer&     Meta::Writer::alias(std::initializer_list<std::string_view> zAlias)
    {
        if(m_meta){
            for(std::string_view z : zAlias)
                m_meta -> m_aliases << z;
        }
        return *this;
    }

    Meta::Writer&     Meta::Writer::description(std::string_view zDescription)
    {
        if(m_meta)
            m_meta -> m_description = std::string_view(zDescription);
        return *this;
    }
    
    Meta::Writer&     Meta::Writer::label(std::string_view zLabel)
    {
        if(m_meta)
            m_meta -> m_label = std::string_view(zLabel);
        return *this;
    }
    
    Meta::Writer&     Meta::Writer::name(std::string_view zName)
    {
        if(m_meta)
            m_meta -> m_name = std::string_view(zName);
        return *this;
    }

    Meta::Writer&     Meta::Writer::options(options_t opts)
    {
        if(m_meta)
            m_meta -> m_flags |= opts;
        return *this;
    }

    Meta::Writer&     Meta::Writer::tag(std::string_view zKey)
    {
        if(m_meta){
            assert("Tag already set!" && !m_meta->m_tags.has(zKey));
            m_meta -> m_tags[zKey] = Any(true);
        }
        return *this;
    }
    
    Meta::Writer&     Meta::Writer::tag(std::string_view zKey, Any&& value)
    {
        if(m_meta){
            assert("Tag already set!" && !m_meta->m_tags.has(zKey));
            m_meta -> m_tags[zKey] = std::move(value);
        }
        return *this;
    }
    

    Meta::Writer&     Meta::Writer::tag(std::string_view zKey, const Any& value)
    {
        if(m_meta){
            assert("Tag already set!" && !m_meta->m_tags.has(zKey));
            m_meta -> m_tags[zKey] = value;
        }
        return *this;
    }
    
    Meta::Writer&   Meta::Writer::tls()
    {
        if(m_meta)
            m_meta -> m_flags |= TLS;
        return *this;
    }

    Meta::Writer&   Meta::Writer::todo()
    {
        if(m_meta)
            m_meta -> m_flags |= TODO;
        return *this;
    }
}