#pragma once
#define DATA_DYN_MEMORY_POSIX_C

#include "../data.h"
#include <assert.h>
#include <sys/mman.h>


_Bool allocate_DynMemory(DynMemory this)
{
	assert(       this && "DynMemory was not provided to allocate");
	assert(!this->data && "Cannot call allocate on DynMemory with data");

	if (MAP_FAILED == (this->data = mmap (
		0, this->capacity, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0))
	) return 0;

	return this->size == 0 || MAP_FAILED != mmap (
		&this->data, this->size,
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}


_Bool deallocate_DynMemory(DynMemory this)
{
	assert(      this && "DynMemory was not provided to deallocate");
	assert(this->data && "Cannot call deallocate on DynMemory without data");

	if (-1 == munmap(this->data, this->capacity)) return 0;

	this->data     = 0;
	this->size     = 0;
	this->capacity = 0;

	return 1;
}


_Bool grow_DynMemory_to(DynMemory this, mut_size size)
{
	assert(      this && "DynMemory was not provided to resize");
	assert(this->data && "Cannot call resize on DynMemory without data");
	assert(this->size < size && size <= this->capacity
		&& "Requested size is not within the capacity");

	if (MAP_FAILED == mmap (
		&this->data, size,
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)
	) return 0;

	this->size = size;
	return 1;
}
