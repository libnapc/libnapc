#if !defined(LIBNAPC_PANIC_h)
	#define LIBNAPC_PANIC_h

	#include <libnapc-internal.h>

	void libnapc_halt(
		const char *file,
		int file_line,
		const char *fn,
		const char *fmt,
		...
	) LIBNAPC_FN_PRINTFLIKE(4, 5);

	/*!
	 * Abort program execution and print a message.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_PANIC
	 * @brief Abort program execution.
	 * @version 2.0.0
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_PANIC("Some error occurred: %s", "Could not open file");
	 */
	#define LIBNAPC_PANIC(fmt, ...) \
		libnapc_halt(__FILE__, __LINE__, __func__, fmt, ## __VA_ARGS__)
#endif
