#if !defined(NAPC_INTTYPES_SIZE_h)
	#define NAPC_INTTYPES_SIZE_h

	/*!
	 * @name napc_size
	 * @brief Memory size type.
	 * @version 1.0.0
	 * @description
	 * Unsigned integer type for holding object sizes.
	 * @rationale
	 * Used because Arduino lacks `ssize_t` in `<stddef.h>`.
	 * For some reason it is defined in `<stdio.h>` but
	 * I don't want to pollute my headers with unnecessary
	 * includes. Also this way, I'm sure what printf specifiers
	 * to use when printing `size_t` resp. `ssize_t`.
	 * (`%zu` is not supported in arduino's libc)
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef unsigned long napc_size;

	// For napc_size literals
	#define NAPC_SIZE_LITERAL(_v) _v ## ul

	/*!
	 * @name NAPC_SIZE_PRINTF
	 * @version 1.0.0
	 * @description
	 * Format specifier for printing `napc_size` variables.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_size var = 1;
	 * 
	 * napc_printf("var is = %" NAPC_SIZE_PRINTF, var);
	 */
	#define NAPC_SIZE_PRINTF "lu"
#endif
