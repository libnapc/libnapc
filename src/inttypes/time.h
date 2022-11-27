#if !defined(LIBNAPC_INTTYPES_TIME_h)
	#define LIBNAPC_INTTYPES_TIME_h

	#include <inttypes/32bit/libnapc_u32.h>

	/*!
	 * Unsigned integer type for holding timestamps.
	 * 
	 * @module Core
	 * @type type:alias
	 * @fullname libnapc_time
	 * @brief Unsigned timestamp int type.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	typedef libnapc_u32 libnapc_time;

	// For libnapc_time literals
	#define LIBNAPC_TIME_LITERAL(_v) LIBNAPC_U32_LITERAL(_v)

	/*!
	 * Format specifier for printing `libnapc_time` variables.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_TIME_PRINTF
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_time var = 1;
	 * 
	 * libnapc_printf("var is = %" LIBNAPC_TIME_PRINT_DEC, var);
	 */
	#define LIBNAPC_TIME_PRINT_DEC PRIu32
#endif
