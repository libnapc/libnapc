#if !defined(LIBNAPC_INTTYPES_U8_h)
	#define LIBNAPC_INTTYPES_U8_h

	#include <stdint.h> // uint8_t
	#include <inttypes.h> // PRIu8

	/*!
	 * Type for unsigned integers with 8 bits width.
	 * 
	 * @module Core
	 * @type type:alias
	 * @fullname libnapc_u8
	 * @brief 8 bit wide unsigned integer 
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	typedef uint8_t libnapc_u8;

	/*!
	 * Used for literal unsigned integers with 8 bits width.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_U8_LITERAL
	 * @version 2.0.0
	 * @param value Value
	 * @note
	 * This macro is only included for consistency's sake.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 var = LIBNAPC_U8_LITERAL(20);
	 */
	#define LIBNAPC_U8_LITERAL(value)  UINT8_C(value)

	/*!
	 * Format specifier for printing `libnapc_u8` variables.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_U8_PRINT_DEC
	 * @version 2.0.0
	 * @note
	 * This macro is only included for consistency's sake.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 var = 1;
	 * 
	 * libnapc_printf("var is = %" LIBNAPC_U8_PRINT_DEC, var);
	 */
	#define LIBNAPC_U8_PRINT_DEC       PRIu8
#endif
