#if !defined(NAPC_INTTYPES_SSIZE_h)
	#define NAPC_INTTYPES_SSIZE_h

	/*!
	 * @name napc_ssize
	 * @brief Signed memory size type.
	 * @version 1.0.0
	 * @description
	 * Signed integer type for holding object sizes.
	 * @rationale
	 * Used because Arduino lacks `ssize_t` in `<stddef.h>`.
	 * 
	 * For some reason it is defined in `<stdio.h>` but
	 * I don't want to pollute my headers with unnecessary
	 * includes.
	 * 
	 * Also this way, I'm sure what printf specifiers
	 * to use when printing `size_t` resp. `ssize_t`.
	 * 
	 * (`%zd` is not supported in arduino's libc)
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef signed long libnapc_ssize;

	// For libnapc_ssize literals
	#define NAPC_SSIZE_LITERAL(_v) _v ## l

	/*!
	 * @name NAPC_SSIZE_PRINTF
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Format specifier for printing `libnapc_ssize` variables.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * libnapc_ssize var = -1;
	 * 
	 * napc_printf("var is = %" LIBNAPC_SSIZE_PRINT_DEC, var);
	 */
	#define LIBNAPC_SSIZE_PRINT_DEC "ld"
#endif
