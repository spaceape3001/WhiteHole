////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "parse32.hpp"
#include <charconv>

#include <yq/errors.hpp>
#include <yq/config/string.hpp>
#include <yq/text/chars32.hpp>

namespace yq {
    //! Trims a string's leading/trailing whitespace by altering parameters
    void    trim_ws(const char32_t*& s, size_t& n)
    {
        while(s && *s && is_space(*s) && n)
            ++s, --n;
        while(s && n && is_space(s[n-1]))
            --n;
    }

    template <typename T>
    Expect<T>   int_from_chars(const char32_t*s, size_t n, int base=10)
    {
        char    buf[kMaxFormattingBuffer+1]{};
        size_t  k   = std::min(n,kMaxFormattingBuffer);
        for(size_t i=0;i<k;++i)
            buf[i]  = (char) std::min((char32_t) 127, s[i]);
        T    res = 0;
        auto [p,ec] = std::from_chars(buf, buf+k, res, base);
        if(ec != std::errc())
            return std::unexpected( std::make_error_code(ec));
        return res;
    }

    unsigned_x  to_hex(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<unsigned int>(s, n, 16);
    }


    unsigned_x  to_hex(std::u32string_view s)
    {
        return to_hex(s.data(), s.size());
    }

    uint8_x  to_hex8(const char32_t*s, size_t n)
    {
        if(!s)  
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint8_t>(s, n, 16);
    }

    uint8_x  to_hex8(std::u32string_view s)
    {
        return to_hex8(s.data(), s.size());
    }

    uint16_x  to_hex16(const char32_t*s, size_t n)
    {
        if(!s)  
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint16_t>(s, n, 16);
    }

    uint16_x  to_hex16(std::u32string_view s)
    {
        return to_hex16(s.data(), s.size());
    }

    uint32_x  to_hex32(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint32_t>(s, n, 16);
    }

    uint32_x  to_hex32(std::u32string_view s)
    {
        return to_hex32(s.data(), s.size());
    }

    uint64_x  to_hex64(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint64_t>(s, n, 16);
    }

    uint64_x  to_hex64(std::u32string_view s)
    {
        return to_hex64(s.data(), s.size());
    }
    
    integer_x  to_int(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<int>(s,n);
    }

    integer_x   to_int(std::u32string_view s)
    {
        return to_int(s.data(), s.size());
    }

    int8_x  to_int8(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<int8_t>(s,n);
    }

    int8_x  to_int8(std::u32string_view s)
    {
        return to_int8(s.data(), s.size());
    }


    int16_x  to_int16(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<int16_t>(s,n);
    }

    int16_x  to_int16(std::u32string_view s)
    {
        return to_int16(s.data(), s.size());
    }

    int32_x  to_int32(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<int32_t>(s,n);
    }

    int32_x  to_int32(std::u32string_view s)
    {
        return to_int32(s.data(), s.size());
    }


    int64_x  to_int64(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<int64_t>(s,n);
    }

    int64_x  to_int64(std::u32string_view s)
    {
        return to_int64(s.data(), s.size());
    }

    integer_x  to_integer(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<int>(s,n);
    }

    integer_x  to_integer(std::u32string_view s)
    {
        return to_integer(s.data(), s.size());
    }
    

    uint8_x  to_octal8(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint8_t>(s,n,8);
    }
    
    uint8_x  to_octal8(std::u32string_view s)
    {
        return to_octal8(s.data(), s.size());
    }

    uint16_x  to_octal16(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint16_t>(s,n,8);
    }
    
    uint16_x  to_octal16(std::u32string_view s)
    {
        return to_octal16(s.data(), s.size());
    }

    uint32_x  to_octal32(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint32_t>(s,n,8);
    }
    
    uint32_x  to_octal32(std::u32string_view s)
    {
        return to_octal32(s.data(), s.size());
    }

    uint64_x  to_octal64(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint64_t>(s,n,8);
    }

    uint64_x  to_octal64(std::u32string_view s)
    {
        return to_octal64(s.data(), s.size());
    }

    short_x  to_short(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<short>(s,n);
    }

    short_x  to_short(std::u32string_view s)
    {
        return to_short(s.data(), s.size());
    }


    unsigned_x  to_uint(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<unsigned>(s,n);
    }

    unsigned_x  to_uint(std::u32string_view s)
    {
        return to_uint(s.data(), s.size());
    }

    uint8_x     to_uint8(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint8_t>(s,n);
    }

    uint8_x     to_uint8(std::u32string_view s)
    {
        return to_uint8(s.data(), s.size());
    }

    uint16_x    to_uint16(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint16_t>(s,n);
    }

    uint16_x    to_uint16(std::u32string_view s)
    {
        return to_uint16(s.data(), s.size());
    }

    uint32_x    to_uint32(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint32_t>(s,n);
    }

    uint32_x    to_uint32(std::u32string_view s)
    {
        return to_uint32(s.data(), s.size());
    }

    uint64_x    to_uint64(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<uint64_t>(s,n);
    }

    uint64_x    to_uint64(std::u32string_view s)
    {
        return to_uint64(s.data(), s.size());
    }

    unsigned_x  to_uinteger(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<unsigned int>(s,n);
    }

    unsigned_x  to_uinteger(std::u32string_view s)
    {
        return to_uinteger(s.data(), s.size());
    }

    unsigned_x  to_unsigned(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<unsigned int>(s,n);
    }

    unsigned_x  to_unsigned(std::u32string_view s)
    {
        return to_unsigned(s.data(), s.size());
    }

    ushort_x    to_ushort(const char32_t*s, size_t n)
    {
        if(!s)
            return errors::null_pointer();
        trim_ws(s,n);
        if(!n)
            return errors::empty_string();
        return int_from_chars<unsigned short>(s,n);
    }


    ushort_x    to_ushort(std::u32string_view s)
    {
        return to_ushort(s.data(), s.size());
    }
    }