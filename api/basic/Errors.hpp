////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/ErrorDB.hpp>

namespace yq {
    namespace errors {
        using bad_argument              = error_db::entry<"Bad argument provided">;
        using cant_open_read            = error_db::entry<"Unable to open file for reading">;
        using cant_open_write           = error_db::entry<"Unable to open file for writing">;
        using const_object_violation    = error_db::entry<"Constant object violated">;
        using failed_to_write_file      = error_db::entry<"Failed to write to the file">;
        using filepath_empty            = error_db::entry<"Filepath is empty">;
        using getter_failed             = error_db::entry<"Getter function returned false">;
        using incompatible_types        = error_db::entry<"Incompatible types">;
        using insufficient_arguments    = error_db::entry<"Not enough arguments for method call">;
        using internal_error            = error_db::entry<"Internal consistency error">;
        using invalid_conversion        = error_db::entry<"Cannot convert invalid to anything else">;
        using invalid_conversion        = error_db::entry<"Cannot convert invalid to anything else">;
        using name_lookup_failed        = error_db::entry<"Name Lookup Failed" >;
        using no_getter                 = error_db::entry<"No getter exists" >;
        using no_setter                 = error_db::entry<"No setter exists" >;
        using no_handler                = error_db::entry<"No handler exists" >;
        using no_conversion_handler     = error_db::entry<"No handler registered for desired conversion" >;
        using no_print_handler          = error_db::entry<"No print handler registered" >;
        using no_write_handler          = error_db::entry<"No print handler registered" >;
        using none                      = std::error_code;
        using not_read_enabled          = error_db::entry<"Not read enabled">;
        using not_write_enabled         = error_db::entry<"Not write enabled">;
        using null_any_type             = error_db::entry<"Null type in Any detected" >;
        using null_destination          = error_db::entry<"Destination is a NULL pointer">;
        using null_object               = error_db::entry<"Object is a NULL pointer" >;
        using null_pointer              = error_db::entry<"Null pointer not allowed" >;
        using null_result               = error_db::entry<"Result is a NULL pointer" >;
        using null_value                = error_db::entry<"Value is a NULL pointer" >;
        using parser_failed             = error_db::entry<"Parser failed to parse string">;
        using setter_failed             = error_db::entry<"Setter function returned false">;
        using todo                      = error_db::entry<"Feature is not yet implemented (TODO)">;
        using xml_bad_syntax            = error_db::entry<"XML syntax failure">;
        using xml_no_root_element       = error_db::entry<"XML document has no sutable root element">;
        using xml_wrong_document_node   = error_db::entry<"XML document type does not match expectations">;
    }
}
