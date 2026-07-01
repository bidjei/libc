#pragma once
#define code
#include <stddef.h>
#include <stdint.h>

typedef        uint8_t        byte,        *Byte;
typedef struct byte_list      byte_list,   *Byte_List;
typedef struct object         object,      *Object;
typedef struct symbol         symbol,      *Symbol;
typedef struct symbol_list    symbol_list, *Symbol_List;
typedef        byte_list      text,        *Text;
typedef struct type           type,        *Type;
typedef struct type_list      type_list,   *Type_List;


struct byte_list      { size_t length; Byte content; };

struct symbol         { text name; byte_list content;};
struct symbol_list    { size_t length; Symbol content; };
struct type           { text name; size_t size; };
struct type_list      { size_t length; Type content; };
struct object         { type_list types; symbol_list symbols; };
