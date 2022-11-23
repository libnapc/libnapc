#if !defined(NAPC_INTTYPES_TIME_h)
	#define NAPC_INTTYPES_TIME_h

	#include <inttypes/32bit/libnapc_u32.h>

	/*!
	 * @name napc_time
	 * @brief Unsigned timestamp int type.
	 * @version 1.0.0
	 * @description
	 * Unsigned integer type for holding timestamps.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef libnapc_u32 libnapc_time;

	// For napc_time literals
	#define NAPC_TIME_LITERAL(_v) NAPC_U32_LITERAL(_v)

	/*!
	 * @name NAPC_TIME_PRINTF
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Format specifier for printing `napc_time` variables.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_time var = 1;
	 * 
	 * napc_printf("var is = %" LIBNAPC_TIME_PRINT_DEC, var);
	 */
	#define LIBNAPC_TIME_PRINT_DEC PRIu32
#endif
