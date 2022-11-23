#if !defined(LIBNAPC_INTERNAL_h)
	#define LIBNAPC_INTERNAL_h

	#include <stdbool.h> // bool
	#include <stdlib.h> // NULL, free()
	#include <stdarg.h> // va_list

	#include <libnapc-compiler.h>

	#define NAPC_CONCAT_(a, b) a ## b
	#define NAPC_CONCAT(a, b) NAPC_CONCAT_(a, b)

	#include <inttypes/inttypes.h>
#endif
