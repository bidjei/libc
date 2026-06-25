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
typedef union  mut_uint_array  mut_uint_array, *MutUIntArray;
typedef        size_t                mut_size, *MutSize;
typedef struct mut_memory          mut_memory, *MutMemory;
typedef const  mut_byte                  byte, *Byte;
typedef const  mut_diff                  diff, *Diff;
typedef const  mut_size                  size, *Size;
typedef const  mut_memory              memory, *Memory;


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