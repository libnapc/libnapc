#if !defined(LIBNAPC_INTERNAL_h)
	#define LIBNAPC_INTERNAL_h

	#define LIBNAPC_CONCAT_(a, b) a ## b
	#define LIBNAPC_CONCAT(a, b) LIBNAPC_CONCAT_(a, b)

	#include <stdbool.h> // bool
	#include <stdlib.h> // free()
	#include <stddef.h> // NULL
	#include <stdarg.h> // va_list

	#include <libnapc-compiler.h>
	#include <inttypes/inttypes.h>
#endif
