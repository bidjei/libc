#pragma once
#define DATA_DYN_MEMORY_C

// IWYU pragma: begin_exports
#if __has_include(<sys/mman.h>)
	#include "dyn_memory.posix.c"
#elif defined(_WIN32)
	#include "dyn_memory.win32.c"
#else
	_Static_assert(0, "unsupported platform");
#endif