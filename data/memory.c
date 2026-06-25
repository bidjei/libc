#pragma once
#define DATA_MEMORY_C

#include "../data.h"
#include <assert.h>
#include <stdlib.h>


_Bool allocate_memory (MutMemory this)
{
	assert(      this && "MutMemory was not provided to allocate");
	assert(this->size && "MutMemory has no size to allocate");

	this->data = malloc(this->size);
	return this->data;
}


_Bool deallocate_memory (MutMemory this)
{
	assert(      this && "MutMemory was not provided to deallocate");
	assert(this->data && "Memory has nothing to deallocate");

	free(this->data);
	return 1;
}


_Bool grow_memory_to (MutMemory this, mut_size size) {
	assert(this              && "MutMemory was not provided to grow");
	assert(this->size < size && "Requested size is not within the capacity");

	MutAny data = realloc(this->data, size);
	if (data) {
		this->data = data;
		this->size = size;
	}
	return this->data;
}