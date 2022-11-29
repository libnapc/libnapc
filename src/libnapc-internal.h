#if !defined(LIBNAPC_INTERNAL_h)
	#define LIBNAPC_INTERNAL_h

	#define LIBNAPC_CONCAT_(a, b) a ## b
	#define LIBNAPC_CONCAT(a, b) LIBNAPC_CONCAT_(a, b)

	#define LIBNAPC_ARRAY_ELEMENTS(array) (sizeof(array) / sizeof(* array))

	/**
	 * stop compilation if LIBNAPC_INCLUDE_TESTS is defined but LIBNAPC_DEBUG isn't.
	 * LIBNAPC_INCLUDE_TESTS requires LIBNAPC_DEBUG to be present/set.
	 */
	#if defined(LIBNAPC_INCLUDE_TESTS) && !defined(LIBNAPC_DEBUG)
		#error LIBNAPC_INCLUDE_TESTS is set, but LIBNAPC_DEBUG is not. Make sure to define both.
	#endif

	#include <stdbool.h> // bool
	#include <stdlib.h> // free()
	#include <stddef.h> // NULL
	#include <stdarg.h> // va_list

	#include <libnapc-compiler.h>
	#include <inttypes/inttypes.h>
#endif
