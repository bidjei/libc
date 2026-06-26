#pragma once
#define DATA_DYN_MEMORY_SPEC_C

#include "dyn_memory.c" // IWYU pragma: keep
#include <assert.h>

void test_dyn_memory()
{
	#define MiB (1024 * 1024)
	dyn_uint_array mock = {.size = 1024, .capacity = MiB};

	assert(allocate(&mock.memory));
	assert(array_length(&mock) == 1024 / sizeof(uint));
	assert(mock.items != 0);
	assert(mock.size == 1024);
	assert(mock.capacity == MiB);
	assert(grow_to(&mock.memory, 2048));
	assert(mock.items != 0);
	assert(mock.size == 2048);
	assert(mock.capacity == MiB);
	assert(deallocate(&mock.memory));
	assert(mock.items == 0 && mock.size == 0 && mock.capacity == 0);
}
