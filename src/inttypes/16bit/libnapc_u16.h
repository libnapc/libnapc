#if !defined(LIBNAPC_INTTYPES_U16_h)
	#define LIBNAPC_INTTYPES_U16_h

	#include <stdint.h> // uint16_t
	#include <inttypes.h> // PRIu16

	/*!
	 * Type for unsigned integers with 16 bits width.
	 * 
	 * @module Core
	 * @type type:alias
	 * @fullname libnapc_u16
	 * @brief 16 bit wide unsigned integer 
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	typedef uint16_t libnapc_u16;

	/*!
	 * Used for literal unsigned integers with 16 bits width.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_U16_LITERAL
	 * @version 2.0.0
	 * @param value Value
	 * @note
	 * This macro is only included for consistency's sake.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u16 var = LIBNAPC_U16_LITERAL(1234);
	 */
	#define LIBNAPC_U16_LITERAL(value) UINT16_C(value)

	/*!
	 * Format specifier for printing `napc_u16` variables.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_U16_PRINT_DEC
	 * @version 2.0.0
	 * @note
	 * This macro is only included for consistency's sake.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u16 var = 1;
	 * 
	 * libnapc_printf("var is = %" LIBNAPC_U16_PRINT_DEC, var);
	 */
	#define LIBNAPC_U16_PRINT_DEC      PRIu16
#endif
