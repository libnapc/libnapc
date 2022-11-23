#if !defined(LIBNAPC_INTTYPES_SIZE_h)
	#define LIBNAPC_INTTYPES_SIZE_h

	/*!
	 * @name napc_size
	 * @brief Memory size type.
	 * @version 1.0.0
	 * @description
	 * Unsigned integer type for holding object sizes.
	 * @rationale
	 * Used because Arduino lacks `size_t` in `<stddef.h>`.
	 * 
	 * For some reason it is defined in `<stdio.h>` but
	 * I don't want to pollute my headers with unnecessary
	 * includes.
	 * 
	 * Also this way, I'm sure what printf specifiers
	 * to use when printing `size_t` resp. `ssize_t`.
	 * 
	 * (`%zu` is not supported in arduino's libc)
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef unsigned long libnapc_size;

	// For napc_size literals
	#define NAPC_SIZE_LITERAL(_v) _v ## ul

	/*!
	 * @name NAPC_SIZE_PRINTF
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Format specifier for printing `napc_size` variables.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * libnapc_size var = 1;
	 * 
	 * napc_printf("var is = %" LIBNAPC_SIZE_PRINT_DEC, var);
	 */
	#define LIBNAPC_SIZE_PRINT_DEC "lu"
#endif
