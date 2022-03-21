#if !defined(NAPC_INTTYPES_U8_h)
	#define NAPC_INTTYPES_U8_h

	#include <stdint.h> // uint8_t
	#include <inttypes.h> // PRIu8

	/*!
	 * @name napc_u8
	 * @brief 8 bit wide unsigned integer 
	 * @version 1.0.0
	 * @description
	 * Type for unsigned integers with 8 bits width.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef uint8_t napc_u8;

	/*!
	 * @name NAPC_U8_LITERAL
	 * @version 1.0.0
	 * @description
	 * Used for literal unsigned integers with 8 bits width.
	 * @param n/a value Value
	 * @rationale
	 * This macro is only included for consistency's sake.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u8 var = NAPC_U8_LITERAL(20);
	 */
	#define NAPC_U8_LITERAL(value)  UINT8_C(value)

	/*!
	 * @name NAPC_U8_PRINTF
	 * @version 1.0.0
	 * @description
	 * Format specifier for printing `napc_u8` variables.
	 * @rationale
	 * This macro is only included for consistency's sake.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u8 var = 1;
	 * 
	 * napc_printf("var is = %" NAPC_U8_PRINTF, var);
	 */
	#define NAPC_U8_PRINTF       PRIu8
#endif
