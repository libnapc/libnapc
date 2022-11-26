#if !defined(LIBNAPC_INTTYPES_U32_h)
	#define LIBNAPC_INTTYPES_U32_h

	#include <stdint.h> // uint32_t
	#include <inttypes.h> // PRIu32

	/*!
	 * Type for unsigned integers with 32 bits width.
	 * 
	 * @module Core
	 * @type type:alias
	 * @fullname libnapc_u32
	 * @brief 32 bit wide unsigned integer 
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	typedef uint32_t libnapc_u32;

	/*!
	 * Used for literal unsigned integers with 32 bits width.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_U32_LITERAL
	 * @version 2.0.0
	 * @param value Value
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u32 var = LIBNAPC_U32_LITERAL(12345);
	 */
	#define LIBNAPC_U32_LITERAL(value) UINT32_C(value)

	/*!
	 * Format specifier for printing `libnapc_u32` variables.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_U32_PRINT_DEC
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u32 var = 1;
	 * 
	 * libnapc_printf("var is = %" LIBNAPC_U32_PRINT_DEC, var);
	 */
	#define LIBNAPC_U32_PRINT_DEC      PRIu32
#endif
