#if !defined(LIBNAPC_INTTYPES_SSIZE_h)
	#define LIBNAPC_INTTYPES_SSIZE_h

	/*!
	 * Signed integer type for holding object sizes.
	 * 
	 * @module Core
	 * @type type:alias
	 * @fullname libnapc_ssize
	 * @brief Signed memory size type.
	 * @version 2.0.0
	 * @note
	 * Used because Arduino lacks `ssize_t` in `<stddef.h>`.
	 * 
	 * For some reason it is defined in `<stdio.h>` but
	 * we don't want to pollute the library headers with unnecessary
	 * includes.
	 * 
	 * Also this way it is clear what printf specifiers
	 * to use when printing `size_t` resp. `ssize_t`.
	 * 
	 * (`%zd` is not supported in arduino's libc)
	 * @changelog 2.0.0 initial version
	 */
	typedef signed long libnapc_ssize;

	// For libnapc_ssize literals
	#define LIBNAPC_SSIZE_LITERAL(_v) _v ## l

	/*!
	 * Format specifier for printing `libnapc_ssize` variables.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_SSIZE_PRINT_DEC
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_ssize var = -1;
	 * 
	 * libnapc_printf("var is = %" LIBNAPC_SSIZE_PRINT_DEC, var);
	 */
	#define LIBNAPC_SSIZE_PRINT_DEC "ld"
#endif
