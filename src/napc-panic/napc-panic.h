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
	 * @name NAPC_PANIC
	 * @module Core
	 * @brief Abort program execution.
	 * @version 1.0.0
	 * @description
	 * Abort program execution and print a message.
	 * @param _cstring_ fmt printf()-like format string.
	 * @param n/a ... Values to incorporate into string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_PANIC("Some error occurred: %s", "Could not open file");
	 */
	#define LIBNAPC_PANIC(fmt, ...) \
		libnapc_halt(__FILE__, __LINE__, __func__, fmt, ## __VA_ARGS__)
#endif
