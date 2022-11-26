#if !defined(LIBNAPC_INTTYPES_SIZE_h)
	#define LIBNAPC_INTTYPES_SIZE_h

	/*!
	 * Unsigned integer type for holding object sizes.
	 * 
	 * @module Core
	 * @type type:alias
	 * @fullname libnapc_size
	 * @brief Memory size type.
	 * @version 2.0.0
	 * @note
	 * Used because Arduino lacks `size_t` in `<stddef.h>`.
	 * 
	 * For some reason it is defined in `<stdio.h>` but
	 * we don't want to pollute the library headers with unnecessary
	 * includes.
	 * 
	 * Also this way it is clear what printf specifiers
	 * to use when printing `size_t` resp. `ssize_t`.
	 * 
	 * (`%zu` is not supported in arduino's libc)
	 * @changelog 2.0.0 initial version
	 */
	typedef unsigned long libnapc_size;

	// For libnapc_size literals
	#define LIBNAPC_SIZE_LITERAL(_v) _v ## ul

	/*!
	 * Format specifier for printing `libnapc_size` variables.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_SIZE_PRINT_DEC
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_size var = 1;
	 * 
	 * libnapc_printf("var is = %" LIBNAPC_SIZE_PRINT_DEC, var);
	 */
	#define LIBNAPC_SIZE_PRINT_DEC "lu"
#endif
