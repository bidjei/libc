#pragma once
#define DATA_H

#include <stdint.h>
#include <stddef.h>
#include <wchar.h>


typedef        void                            *MutAny;
typedef const  void                            *Any;

typedef struct dyn_memory          dyn_memory, *DynMemory;
typedef union  dyn_sint_array  dyn_sint_array, *DynSIntArray;
typedef union  dyn_uint_array  dyn_uint_array, *DynUIntArray;
typedef        uint8_t               mut_byte, *MutByte;
typedef        ssize_t               mut_diff, *MutDiff;
typedef        int                   mut_sint, *MutSInt;
typedef        unsigned              mut_uint, *MutUInt;
typedef union  mut_sint_array  mut_sint_array, *MutSIntArray;
typedef        size_t                mut_size, *MutSize;
typedef        int8_t                  mut_s8, *MutS8;
typedef        int16_t                mut_s16, *MutS16;
typedef        int32_t                mut_s32, *MutS32;
typedef        int64_t                mut_s64, *MutS64;
typedef union  mut_uint_array  mut_uint_array, *MutUIntArray;
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


struct dyn_memory
{
	mut_size size;
	mut_size capacity;
	MutAny   data;
};

struct mut_memory
{
	mut_size size;
	MutAny   data;
};

union mut_sint_array
{
	mut_memory memory;
	struct {
		mut_size size;
		MutSInt  items;
	};
};

union mut_uint_array
{
	mut_memory memory;
	struct {
		mut_size size;
		MutUInt  items;
	};
};

union dyn_sint_array
{
	dyn_memory memory;
	struct {
		mut_size size;
		mut_size capacity;
		MutSInt  items;
	};
};

union dyn_uint_array
{
	dyn_memory memory;
	struct {
		mut_size size;
		mut_size capacity;
		MutUInt  items;
	};
};

#define allocate(descriptor) _Generic((descriptor),        \
    DynMemory: allocate_dyn_memory,                        \
    MutMemory: allocate_memory                             \
)(descriptor)

_Bool allocate_dyn_memory   (DynMemory this);
_Bool allocate_memory       (MutMemory this);


#define deallocate(descriptor) _Generic((descriptor),      \
    DynMemory: deallocate_dyn_memory,                      \
    MutMemory: deallocate_memory                           \
)(descriptor)

_Bool deallocate_dyn_memory (DynMemory this);
_Bool deallocate_memory     (MutMemory this);


#define grow_to(descriptor, size) _Generic((descriptor),   \
    DynMemory: grow_dyn_memory_to,                         \
    MutMemory: grow_memory_to                              \
)(descriptor, size)

_Bool grow_dyn_memory_to (DynMemory this, mut_size size);
_Bool grow_memory_to     (MutMemory this, mut_size size);
