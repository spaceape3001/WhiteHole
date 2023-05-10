////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <meta/MethodInfo.hpp>
#include <meta/MetaWriter.hpp>
#include <meta/GlobalInfo.hpp>
#include <meta/ObjectInfo.hpp>
#include <meta/TypeInfo.hpp>
#include <basic/Any.hpp>
#include <basic/errors.hpp>

#include <basic/Logging.hpp>

namespace yq {
    MethodInfo::MethodInfo(std::string_view zName, const std::source_location& sl, Meta* parentMeta, options_t opts) : Meta(zName, parentMeta, sl)
    {
        assert(parentMeta);

        m_flags |= METHOD | opts;

        if(GlobalInfo* g = to_global(parentMeta)){
            assert(g == &meta<Global>());
            if(g->m_methods.keys.has(zName))
                yCritical() << "Duplicate method on GLOBAL: " << zName;
            g->m_methods << this;
        }
        
        if(ObjectInfo* obj = to_object(parentMeta))
            obj->m_local.methods << this;
        if(TypeInfo* type = to_type(parentMeta))
            type->m_methods << this;
    }
    
    void    MethodInfo::fill_argument_info(size_t n, std::string_view zName, std::string_view zDescription, options_t opts)
    {
        if(n < m_args.size()){
            Meta::Writer w{ const_cast<ArgInfo*>(m_args[n])};
            if(!zName.empty())
                w.name(zName);
            if(!zDescription.empty())
                w.description(zDescription);
            if(opts)
                w.options(opts);
        }
    }

    void    MethodInfo::fill_result_info(std::string_view zName, std::string_view zDescription, options_t opts)
    {
        Meta::Writer w{ const_cast<ArgInfo*>(m_result) };
        if(!zName.empty())
            w.name(zName);
        if(!zDescription.empty())
            w.description(zDescription);
        if(opts)
            w.options(opts);
    }

    //  INVOKATION
    Expect<Any>      MethodInfo::invoke(std::span<const Any> args) const
    {
        return invoke(nullptr, args, false);
    }

    Expect<Any>      MethodInfo::invoke(void* obj, std::span<const Any> args) const
    {
        return invoke(obj, args, false);
    }
    
    Expect<Any>      MethodInfo::invoke(const void* obj, std::span<const Any> args) const
    {
        return invoke(const_cast<void*>(obj), args, true);
    }

    Expect<Any>      MethodInfo::invoke(void* obj, std::span<const Any> args, bool constPtr) const 
    {
        size_t  ac  = arg_count();
        if(args.size() < ac)
            return errors::insufficient_arguments();
        if(!obj && !is_static())
            return errors::null_object();
        if(obj && constPtr && !is_const())
            return errors::const_object_violation();
        if(m_args.size() < ac)
            return errors::internal_error();
        
        Any                         result;
        void*                       rptr        = nullptr;
        std::vector<const void*>    ptrs;;
        std::vector<Any>            data;

            //  guard against results that aren't types
        if(m_result && !m_result->type().is_type())
            return errors::internal_error();
        
        if(ac){
        
            //  quick sanity check to guard against arguments that aren't types
            for(size_t n = 0; n<ac; ++n){
                if(!m_args[n]->type().is_type())
                    return errors::internal_error();
            }
        
            ptrs.resize(ac, nullptr);
            data.resize(ac);
            
            for(size_t n =0; n<ac; ++n){
                const Any& arg  = args[n];
                if(&arg.type() == &m_args[n]->type()){
                    ptrs[n] = arg.raw_ptr();
                    continue;
                }
                
                auto v      = arg.convert(static_cast<const TypeInfo&>(m_args[n]->type()));
                if(!v)
                    return errors::bad_argument();
                
                data[n] = std::move(*v);
                ptrs[n] = data[n].raw_ptr();
            }
        }
    
        if(m_result){
            result  = std::move(Any(static_cast<const TypeInfo&>(m_result->type())));
            rptr    = result.raw_ptr();
        }
        
        std::error_code ec  = _invoke(rptr, obj, ptrs.data());
        if(ec != std::error_code())
            return std::unexpected(ec);
        if(m_result)
            return  std::move(result);
        else
            return Any();
    }
}

