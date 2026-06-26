#pragma once
#define DATA_H

#include <stdint.h>
#include <stddef.h>
#include <wchar.h>


typedef        void                            *MutAny;
typedef const  void                            *Any;

typedef struct dyn_memory          dyn_memory, *DynMemory;

typedef union  dyn_sint_array  dyn_sint_array, *DynSIntArray;
typedef union  dyn_s8_array      dyn_s8_array, *DynS8Array;
typedef union  dyn_s16_array    dyn_s16_array, *DynS16Array;
typedef union  dyn_s32_array    dyn_s32_array, *DynS32Array;
typedef union  dyn_s64_array    dyn_s64_array, *DynS64Array;

typedef union  dyn_uint_array  dyn_uint_array, *DynUIntArray;
typedef union  dyn_u8_array      dyn_u8_array, *DynU8Array;
typedef union  dyn_u16_array    dyn_u16_array, *DynU16Array;
typedef union  dyn_u32_array    dyn_u32_array, *DynU32Array;
typedef union  dyn_u64_array    dyn_u64_array, *DynU64Array;

typedef        uint8_t               mut_byte, *MutByte;
typedef        ssize_t               mut_diff, *MutDiff;
typedef        int                   mut_sint, *MutSInt;
typedef        unsigned              mut_uint, *MutUInt;

typedef union  mut_sint_array  mut_sint_array, *MutSIntArray;
typedef union  mut_s8_array      mut_s8_array, *MutS8Array;
typedef union  mut_s16_array    mut_s16_array, *MutS16Array;
typedef union  mut_s32_array    mut_s32_array, *MutS32Array;
typedef union  mut_s64_array    mut_s64_array, *MutS64Array;

typedef        size_t                mut_size, *MutSize;
typedef        int8_t                  mut_s8, *MutS8;
typedef        int16_t                mut_s16, *MutS16;
typedef        int32_t                mut_s32, *MutS32;
typedef        int64_t                mut_s64, *MutS64;

typedef union  mut_uint_array  mut_uint_array, *MutUIntArray;
typedef union  mut_s8_array      mut_s8_array, *MutS8Array;
typedef union  mut_s16_array    mut_s16_array, *MutS16Array;
typedef union  mut_s32_array    mut_s32_array, *MutS32Array;
typedef union  mut_s64_array    mut_s64_array, *MutS64Array;

typedef        uint8_t                 mut_u8, *MutU8;
typedef        uint16_t               mut_u16, *MutU16;
typedef        uint32_t               mut_u32, *MutU32;
typedef        uint64_t               mut_u64, *MutU64;

typedef struct mut_memory          mut_memory, *MutMemory;
typedef const  mut_byte                  byte, *Byte;
typedef const  mut_diff                  diff, *Diff;
typedef const  mut_size                  size, *Size;
typedef const  mut_memory              memory, *Memory;

typedef const  mut_sint_array      sint_array, *SIntArray;
typedef const  int8_t                      s8, *S8;
typedef const  int16_t                    s16, *S16;
typedef const  int32_t                    s32, *S32;
typedef const  int64_t                    s64, *S64;

typedef const  mut_uint_array      uint_array, *UIntArray;
typedef const  uint8_t                     u8, *U8;
typedef const  uint16_t                   u16, *U16;
typedef const  uint32_t                   u32, *U32;
typedef const  uint64_t                   u64, *U64;


struct dyn_memory    { mut_size size; mut_size capacity; MutAny data; };
struct mut_memory    { mut_size size; MutAny   data; };

union mut_sint_array { mut_memory  memory; struct { mut_size size; MutSInt items; }; };
union mut_s8_array   { mut_memory  memory; struct { mut_size size; MutS8   items; }; };
union mut_s16_array  { mut_memory  memory; struct { mut_size size; MutS16  items; }; };
union mut_s32_array  { mut_memory  memory; struct { mut_size size; MutS32  items; }; };
union mut_s64_array  { mut_memory  memory; struct { mut_size size; MutS64  items; }; };

union mut_uint_array { mut_memory  memory; struct { mut_size size; MutUInt items; }; };
union mut_u8_array   { mut_memory  memory; struct { mut_size size; MutU8   items; }; };
union mut_u16_array  { mut_memory  memory; struct { mut_size size; MutU16  items; }; };
union mut_u32_array  { mut_memory  memory; struct { mut_size size; MutU32  items; }; };
union mut_u64_array  { mut_memory  memory; struct { mut_size size; MutU64  items; }; };

union dyn_sint_array { dyn_memory  memory; struct { mut_size size; mut_size capacity; MutSInt items; }; };
union dyn_s8_array   { dyn_memory  memory; struct { mut_size size; mut_size capacity; MutS8   items; }; };
union dyn_s16_array  { dyn_memory  memory; struct { mut_size size; mut_size capacity; MutS16  items; }; };
union dyn_s32_array  { dyn_memory  memory; struct { mut_size size; mut_size capacity; MutS32  items; }; };
union dyn_s64_array  { dyn_memory  memory; struct { mut_size size; mut_size capacity; MutS64  items; }; };

union dyn_uint_array { dyn_memory  memory; struct { mut_size size; mut_size capacity; MutUInt items; }; };
union dyn_u8_array   { dyn_memory  memory; struct { mut_size size; mut_size capacity; MutU8   items; }; };
union dyn_u16_array  { dyn_memory  memory; struct { mut_size size; mut_size capacity; MutU16  items; }; };
union dyn_u32_array  { dyn_memory  memory; struct { mut_size size; mut_size capacity; MutU32  items; }; };
union dyn_u64_array  { dyn_memory  memory; struct { mut_size size; mut_size capacity; MutU64  items; }; };


#define allocate(this) _Generic((this), \
	DynMemory: allocate_DynMemory, MutMemory: allocate_MutMemory)(this)

_Bool allocate_DynMemory   (DynMemory this);
_Bool allocate_MutMemory   (MutMemory this);


#define deallocate(this) _Generic((this), \
	DynMemory: deallocate_DynMemory, MutMemory: deallocate_MutMemory)(this)

_Bool deallocate_DynMemory (DynMemory this);
_Bool deallocate_MutMemory  (MutMemory this);


#define grow_to(descriptor, size) _Generic((descriptor), \
	DynMemory: grow_DynMemory_to, MutMemory: grow_MutMemory_to)(descriptor, size)

_Bool grow_DynMemory_to (DynMemory this, mut_size size);
_Bool grow_MutMemory_to (MutMemory this, mut_size size);
