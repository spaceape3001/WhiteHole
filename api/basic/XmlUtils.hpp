////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/TextUtils.hpp>
#include <basic/Enum.hpp>
#include <basic/Flag.hpp>

#include "rapidxml.hpp"
#include <type_traits>
#include <vector>
#include <set>

namespace yq {

    /*! \brief Converts xml node/attribute to boolean
    
        This parses the text contained by the XML node/attribute,
        returns it as a boolean.
    */
    Expect<bool>            to_boolean(const XmlBase*);

    /*! \brief Converts xml node/attribute to double
    
        This parses the text contained by the XML node/attribute,
        returns it as a double.
    */
    Expect<double>          to_double(const XmlBase*);

    /*! \brief Converts xml node/attribute to float
    
        This parses the text contained by the XML node/attribute,
        returns it as a float.
    */
    Expect<float>           to_float(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned hexadecimal integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned hexadecimal integer
    */
    Expect<unsigned>        to_hex(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned 8-bit hexadecimal integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned hexadecimal 8-bit integer
    */
    Expect<uint8_t>         to_hex8(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned 16-bit hexadecimal integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned hexadecimal 16-bit integer
    */
    Expect<uint16_t>        to_hex16(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned 32-bit hexadecimal integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned hexadecimal 32-bit integer
    */
    Expect<uint32_t>        to_hex32(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned 64-bit hexadecimal integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned hexadecimal 64-bit integer
    */
    Expect<uint64_t>        to_hex64(const XmlBase*);

    /*! \brief Converts xml node/attribute to signed integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an signed integer
    */
    Expect<int>             to_int(const XmlBase*);

    /*! \brief Converts xml node/attribute to signed integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an signed integer
    */
    Expect<int>             to_integer(const XmlBase*);

    /*! \brief Converts xml node/attribute to signed 8-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an signed 8-bit integer
    */
    Expect<int8_t>          to_int8(const XmlBase*);

    /*! \brief Converts xml node/attribute to signed 16-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an signed 16-bit integer
    */
    Expect<int16_t>         to_int16(const XmlBase*);

    /*! \brief Converts xml node/attribute to signed 32-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an signed 32-bit integer
    */
    Expect<int32_t>         to_int32(const XmlBase*);

    /*! \brief Converts xml node/attribute to signed 64-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an signed 64-bit integer
    */
    Expect<int64_t>         to_int64(const XmlBase*);

    /*! \brief Converts xml node/attribute to signed short integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an signed short integer
    */
    Expect<short>           to_short(const XmlBase*);
    
    /*! \brief Converts to string view
    
        \note Return value is a REFERENCE to the given data, therefore, copy off if the XML is being altered/destroyed.
    */
    std::string_view        to_string_view(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned integer
    */
    Expect<unsigned>        to_uint(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned 8-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned 8-bit integer
    */
    Expect<uint8_t>         to_uint8(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned 16-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned 16-bit integer
    */
    Expect<uint16_t>        to_uint16(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned 32-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned 32-bit integer
    */
    Expect<uint32_t>        to_uint32(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned 64-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned 64-bit integer
    */
    Expect<uint64_t>        to_uint64(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned integer
    */
    Expect<unsigned>        to_uinteger(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned integer
    */
    Expect<unsigned>        to_unsigned(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned short integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned short integer
    */
    Expect<unsigned short>  to_ushort(const XmlBase*);

    /*! \brief Converts xml node/attribute to enumerated value
    
        This parses the text contained by the XML node/attribute,
        returns it as an enumerate value of type E
        
        \typename E enumeration type to parse for
    */
    template <typename E>
    Expect<E>           to_enum(const XmlBase*xb)
    {
        if(xb -> value_size() == 0)
            return E::default_value();
        auto   v    = E::value_for(to_string_view(xb));
        if(v)
            return *v;
        return v;
    }

    /*! \brief Parses to bool
    
        Parses the contents of the tag/attribute, interpreting it as boolean true/false.
        
        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<bool>            x_boolean(const XmlBase*);

    /*! \brief Converts xml node/attribute to double
    
        This parses the text contained by the XML node/attribute,
        returns it as a double.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<double>          x_double(const XmlBase*);

    /*! \brief Converts xml node/attribute to float
    
        This parses the text contained by the XML node/attribute,
        returns it as a float.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<float>           x_float(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned hexadecimal integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<unsigned>        x_hex(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned hexadecimal 8-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<uint8_t>         x_hex8(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned hexadecimal 16-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<uint16_t>        x_hex16(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned hexadecimal 32-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<uint32_t>        x_hex32(const XmlBase*);

    /*! \brief Converts xml node/attribute to unsigned hexadecimal 64-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an unsigned integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<uint64_t>        x_hex64(const XmlBase*);

    /*! \brief Converts xml node/attribute to integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<int>             x_int(const XmlBase*);

    /*! \brief Converts xml node/attribute to integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<int>             x_integer(const XmlBase*);

    /*! \brief Converts xml node/attribute to 8-bit integer
    
        This parses the text contained by the XML node/attribute,
        returns it as an integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<int8_t>          x_int8(const XmlBase*);

    /*! \brief Converts xml node/attribute to 16-bit integer
    
        This parses the text contained by the XML node/attribute, returns it as an integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<int16_t>         x_int16(const XmlBase*);

    /*! \brief Converts xml node/attribute to 32-bit integer
    
        This parses the text contained by the XML node/attribute, returns it as an integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<int32_t>         x_int32(const XmlBase*);

    /*! \brief Converts xml node/attribute to 64-bit integer
    
        This parses the text contained by the XML node/attribute, returns it as an integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<int64_t>         x_int64(const XmlBase*);

    /*! \brief Converts xml node/attribute to a short integer
    
        This parses the text contained by the XML node/attribute, returns it as a short integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<short>           x_short(const XmlBase*);
    
    /*! \brief Converts to string 
    
        This returns the string to the FIRST bit of data for the node/attribute, which is normally 
        sufficient for to_(whatever).
    */
    std::string             x_string(const XmlBase*);
    
    /*! \brief Converts to string view
    
        This returns the string view to the FIRST bit of data for the node/attribute, which is normally 
        sufficient for to_(whatever).
    
        \note Return value is a REFERENCE to the given data, therefore, copy off if the XML is being altered/destroyed.
    */
    std::string_view        x_string_view(const XmlBase*);

    /*! \brief Converts xml node/attribute to an unsigned integer
    
        This parses the text contained by the XML node/attribute, returns it as an unsigned integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<unsigned>        x_uint(const XmlBase*);

    /*! \brief Converts xml node/attribute to an unsigned 8-bit integer
    
        This parses the text contained by the XML node/attribute, returns it as an unsigned 8-bit integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<uint8_t>         x_uint8(const XmlBase*);

    /*! \brief Converts xml node/attribute to an unsigned 16-bit integer
    
        This parses the text contained by the XML node/attribute, returns it as an unsigned 16-bit integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<uint16_t>        x_uint16(const XmlBase*);

    /*! \brief Converts xml node/attribute to an unsigned 32-bit integer
    
        This parses the text contained by the XML node/attribute, returns it as an unsigned 32-bit integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<uint32_t>        x_uint32(const XmlBase*);

    /*! \brief Converts xml node/attribute to an unsigned 64-bit integer
    
        This parses the text contained by the XML node/attribute, returns it as an unsigned 64-bit integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<uint64_t>        x_uint64(const XmlBase*);

    /*! \brief Converts xml node/attribute to an unsigned integer
    
        This parses the text contained by the XML node/attribute, returns it as an unsigned integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<unsigned>        x_uinteger(const XmlBase*);

    /*! \brief Converts xml node/attribute to an unsigned integer
    
        This parses the text contained by the XML node/attribute, returns it as an unsigned integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<unsigned>        x_unsigned(const XmlBase*);

    /*! \brief Converts xml node/attribute to an unsigned short integer
    
        This parses the text contained by the XML node/attribute, returns it as an unsigned short integer.

        \note This is the same as the "to", different name to be unique for read_attribute.
    */
    Expect<unsigned short>  x_ushort(const XmlBase*);

    /*! \brief Converts xml node/attribute to enumerated value
    
        This parses the text contained by the XML node/attribute,
        returns it as an enumerate value of type E
        
        \typename E enumeration type to parse for
    */
    template <typename E>
    Expect<E>           x_enum(const XmlBase*xb)
    {
        if(xb -> value_size() == 0)
            return E::default_value();
        auto v = E::value_for(x_string_view(xb));
        if(v)
            return E(*v);
        return v;
    }
    
    /*! \brief Converts xml node/attribute to flag-set of enumerated value
    
        This parses the text as a comma separated list of enumerations contained by the XML node/attribute,
        returns it as a flag set value of type E
        
        \typename E enumeration type to parse for
    */
    template <typename E>
    Flag<E>             x_flag(const XmlBase* xb)
    {
        Flag<E> ret;
        vsplit(x_string(xb), ',', [&](std::string_view k){
            auto    v   = E::value_for(k);
            if(v)
                ret.set(*v);
        });
        return ret;
    }

    /*! \brief Reads and inteprets attribute
    
        This reads the specified attribute, applies the specified converter to return the value.
    
        \param[in]  xn          XmlNode with the desired attribute
        \parma[in]  pszAttr     attribute being searched for
        \param[in]  pred        Converter of XmlAttribute to value (use one of the x_ methods)
    */
    template <typename Pred>
    auto                read_attribute(const XmlNode* xn, const char* pszAttr, Pred pred)
    {
        using Res = std::invoke_result_t<Pred, const XmlAttribute*>;
        const XmlAttribute*xa   = xn -> first_attribute(pszAttr);
        if(xa)
            return pred(xa);
        return Res();
    }
    
    /*! \brief Reads the FIRST child with tag
    
        This finds the first child element (tag) with the specified name, parses its text using the predicate,
        and returns the result.
        
        \param[in]  xn          Containing/Parent XmlNode
        \param[in]  pszTag      XML element being searched for
        \param[in]  pred        Converter of XmlNode to value (use one of the x_ or xn_ methods)
    */
    template <typename Pred>
    auto                read_child(const XmlNode* xn, const char* pszTag, Pred pred)
    {
        using Res = std::invoke_result_t<Pred, const XmlNode*>;
        const XmlNode*      xb  = xn -> first_node(pszTag);
        if(xb)
            return pred(xb);
        return Res();
    }

    /*! \brief Reads ALL children with tag
    
        This finds ALL child elements with the specified name, parsed using the predicate, and returns the result
        as a vector.
        
        \param[in]  xn          Containing/Parent XmlNode
        \param[in]  pszTag      XML element being searched for
        \param[in]  pred        Converter of XmlNode to value (use one of the x_ or xn_ methods)
    */
    template <typename Pred>
    auto                read_children(const XmlNode* xn, const char* pszTag, Pred pred)
    {
        using Res = std::invoke_result_t<Pred, const XmlNode*>;
        std::vector<Res> ret;
        for(const XmlNode* xb = xn->first_node(pszTag); xb; xb = xb -> next_sibling(pszTag))
            ret.push_back(pred(xb));
        return ret;
    }
    
    /*! \brief Reads ALL children with tag as set of string
    
        This finds ALL child elements with the specified name, returning the result as a string set
        
        \param[in]  xn          Containing/Parent XmlNode
        \param[in]  pszTag      XML element being searched for
    */
    string_set_t        read_child_string_set(const XmlNode* xn, const char* pszTag);


    /*! \brief Counts the child elements with specified name
    
        This finds ALL child elements with the specified name, returning the count.

        \param[in]  xn          Containing/Parent XmlNode
        \param[in]  pszTag      XML element being searched for
    */
    size_t              count_children(const XmlNode*, const char* pszTag);


    /*
        With the exception of bool, the rest use the xml document for allocation purposes
    */

    /*! \brief Determine the document for the given xml object
    */
    XmlDocument*         document_for(XmlBase* xb);

    /*! \brief Writes value as hex
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_hex(XmlBase* xb, uint8_t v);

    /*! \brief Writes value as hex
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_hex(XmlBase* xb, uint16_t v);

    /*! \brief Writes value as hex
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_hex(XmlBase* xb, uint32_t v);

    /*! \brief Writes value as hex
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_hex(XmlBase* xb, uint64_t v);

    /*! \brief Writes value as true/false
    
        This writes the value to the specified Xml object, embeds it as true/false
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, bool v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, double v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, float v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, int8_t v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, int16_t v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, int32_t v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, int64_t v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, uint8_t v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, uint16_t v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, uint32_t v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, uint64_t v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    void                 write_x(XmlBase* xb, std::string_view v);

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    template <typename E>
    void                 write_x(XmlBase* xb, EnumImpl<E> v)
    {
        write_x(xb, v.key());
    }

    /*! \brief Writes value to XML
    
        This writes the value to the specified Xml object.
        
        \param[in] xb   XmlBase object to write to (ie node, attribute, etc)
        \param[in] v    Value to write
    */
    template <typename E>
    void                 write_x(XmlBase* xb, Flag<E> v)
    {
        std::string     build   = v.as_string(","sv);
        write_x(xb, build);
    }

    /*! \brief Writes value to XML Node
    
        This writes the value to the specified Xml node.
        
        \param[in] xn   Xml Node to write to
        \param[in] v    Value to write
    */
    template <typename T>
    void                write_xn(XmlNode*xn, const T& val) 
    {
        write_x(xn, val);
    }


    /*! \brief Writes attribute to node 
    
        This writes the specified attribute to node, needs "write_x" defined for type T.
        
        \param[in] xb       Node to attach attribute to
        \param[in] pszAttr  Attribute name/key
        \param[in] value    Value to record
        \param[in] copyAttr TRUE to actually copy the attribute key into the XML
        
        \note For performance, the const char* is assumed to be a program constant, ie, "key" and is therefore
        not going to die between the invocation of this method and the actual write/destruction.  If this assumption
        is violated, bad things will happen; therefore, setting the copyAttr to TRUE will explicitly allocate/copy
        the attribute name/key into strings for the XML and thereby dodge the dragons.
    */
    template <typename T>
    void                write_attribute(XmlNode* xb, const char* pszAttr, const T& value, bool copyAttr=false)
    {
        assert(xb);
        XmlDocument*    doc = xb -> document();
        assert(doc);
        XmlAttribute*   xa  = doc -> allocate_attribute();
        if(copyAttr){
            xa -> name( doc -> allocate_string(pszAttr));
        } else
            xa -> name(pszAttr);
        xb -> append_attribute(xa);
        write_x(xa, value);
    }


    /*! \brief Writes value to chld node
    
        This writes the specified value as a child-node to the given node, needs "write_xn" defined for type T.
        
        \param[in] xb       Parent node
        \param[in] pszTag   Name/key for the child node
        \param[in] value    Value to record
        \param[in] copyTag  TRUE to actually copy the element name into the XML
        
        \note For performance, the const char* is assumed to be a program constant, ie, "key" and is therefore
        not going to die between the invocation of this method and the actual write/destruction.  If this assumption
        is violated, bad things will happen; therefore, setting the copyTag to TRUE will explicitly allocate/copy
        the element name/key into strings for the XML and thereby dodge the dragons.
    */
    template <typename T>
    XmlNode*             write_child(XmlNode* xb, const char* pszTag, const T& value, bool copyTag=false)
    {
        assert(xb && pszTag);
        XmlDocument*    doc = xb -> document();
        assert(doc);
        XmlNode*        xn  = doc -> allocate_node(rapidxml::node_element);
        if(copyTag){
            xn -> name(doc->allocate_string(pszTag));
        } else 
            xn -> name(pszTag);
        xb->append_node(xn);
        write_xn(xn, value);
        return xn;
    }

    /*! \brief Overload for writing child node
    
        This writes the specified value as a child-node to the given node, needs "write_xn" defined for type T.

        \param[in] xb       Parent node
        \param[in] pszTag   Name/key for the child node
        \param[in] value    Value to record
    */
    template <typename T>
    XmlNode*             write_child(XmlNode* xb, const std::string& pszTag, const T& value)
    {
        return write_child(xb, pszTag.c_str(), value, true);
    }

    /*! \brief Writes set values as child nodes
    
        This writes the entire set as a series of child-nodes to the given node.  Needs "write_xn" defined for type T
        
        \param[in] xb       Parent node
        \param[in] pszTag   Name/key for the child node
        \param[in] values   Values to record
    */
    template <typename T,typename C>
    void    write_children(XmlNode* xb, const char* pszTag, const std::set<T,C>& values)
    {
        assert(xb && pszTag);
        XmlDocument*    doc = xb -> document();
        assert(doc);
        for(const T& v : values){
            XmlNode*    xn  = doc -> allocate_node(rapidxml::node_element, pszTag);
            xb -> append_node(xn);
            write_xn(xn, v);
        }
    }

    /*! \brief Writes vector as child nodes
    
        This writes the entire vector as a series of child-nodes to the given node.  Needs "write_xn" defined for type T
        
        \param[in] xb       Parent node
        \param[in] pszTag   Name/key for the child node
        \param[in] values   Values to record
    */
    template <typename T>
    void    write_children(XmlNode* xb, const char* pszTag, const std::vector<T>& values)
    {
        assert(xb && pszTag);
        XmlDocument*    doc = xb -> document();
        assert(doc);
        for(const T& v : values){
            XmlNode*    xn  = doc -> allocate_node(rapidxml::node_element, pszTag);
            xb -> append_node(xn);
            write_xn(xn, v);
        }
    }

    //! Adds the customary <?xml version=" ... line
    void    xml_start(XmlDocument&);
}
