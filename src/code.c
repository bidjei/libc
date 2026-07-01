#pragma once
#define code_impl

// Pick Implementation

	#if defined (__APPLE__)
		#include "code/code.apple.c"
	#elif defined (__WIN32)
		#include "code/coda.windows.c"
	#else
		#include "code/code.posix.c"
	#endif
