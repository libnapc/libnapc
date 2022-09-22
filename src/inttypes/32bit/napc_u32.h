#if !defined(NAPC_INTTYPES_U32_h)
	#define NAPC_INTTYPES_U32_h

	#include <stdint.h> // uint32_t
	#include <inttypes.h> // PRIu32

	/*!
	 * @name napc_u32
	 * @brief 32 bit wide unsigned integer 
	 * @version 1.0.0
	 * @description
	 * Type for unsigned integers with 32 bits width.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef uint32_t napc_u32;

	/*!
	 * @name NAPC_U32_LITERAL
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Used for literal unsigned integers with 32 bits width.
	 * @param n/a value Value
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u32 var = NAPC_U32_LITERAL(12345);
	 */
	#define NAPC_U32_LITERAL(value) UINT32_C(value)

	/*!
	 * @name NAPC_U32_PRINTF
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Format specifier for printing `napc_u32` variables.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u32 var = 1;
	 * 
	 * napc_printf("var is = %" NAPC_U32_PRINTF, var);
	 */
	#define NAPC_U32_PRINTF      PRIu32
#endif
