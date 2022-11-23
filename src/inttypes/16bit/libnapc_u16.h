#if !defined(LIBNAPC_INTTYPES_U16_h)
	#define LIBNAPC_INTTYPES_U16_h

	#include <stdint.h> // uint16_t
	#include <inttypes.h> // PRIu16

	/*!
	 * @name napc_u16
	 * @brief 16 bit wide unsigned integer 
	 * @version 1.0.0
	 * @description
	 * Type for unsigned integers with 16 bits width.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef uint16_t libnapc_u16;

	/*!
	 * @name NAPC_U16_LITERAL
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Used for literal unsigned integers with 16 bits width.
	 * @param n/a value Value
	 * @rationale
	 * This macro is only included for consistency's sake.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u16 var = NAPC_U16_LITERAL(1234);
	 */
	#define LIBNAPC_U16_LITERAL(value) UINT16_C(value)

	/*!
	 * @name NAPC_U16_PRINTF
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Format specifier for printing `napc_u16` variables.
	 * @rationale
	 * This macro is only included for consistency's sake.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u16 var = 1;
	 * 
	 * napc_printf("var is = %" NAPC_U16_PRINTF, var);
	 */
	#define NAPC_U16_PRINTF      PRIu16
#endif
