#pragma once
#define DATA_DYN_MEMORY_SPEC_C

#include "dyn_memory.c" // IWYU pragma: keep
#include <assert.h>

void test_dyn_memory()
{
	#define MiB (1024 * 1024)
	dyn_memory mock = {.size = 1024, .capacity = MiB};

	assert(allocate(&mock));
	assert(mock.data != 0);
	assert(mock.size == 1024);
	assert(mock.capacity == MiB);
	assert(grow_to(&mock, 2048));
	assert(mock.data != 0);
	assert(mock.size == 2048);
	assert(mock.capacity == MiB);
	assert(deallocate(&mock));
	assert(mock.data == 0 && mock.size == 0 && mock.capacity == 0);
}