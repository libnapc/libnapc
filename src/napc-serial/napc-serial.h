#if !defined(LIBNAPC_SERIAL_h)
	#define LIBNAPC_SERIAL_h

	#include <libnapc-internal.h>

	/*!
	 * Output a string via console or serial.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_puts
	 * @brief Print a string to console/serial.
	 * @version 2.0.0
	 * @param str The string to be printed.
	 * @changelog 2.0.0 initial version
	 * @example
	 * napc_puts("Hello World!");
	 */
	void libnapc_puts(const char *str);

	/*!
	 * Output a single character via console or serial.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_putc
	 * @brief Print a character to console/serial.
	 * @version 2.0.0
	 * @param ch The character to be printed.
	 * @changelog 2.0.0 initial version
	 * @example
	 * napc_putc('H');
	 * napc_putc('e');
	 * napc_putc('l');
	 * napc_putc('l');
	 * napc_putc('o');
	 * napc_putc('!');
	 */
	void libnapc_putc(char ch);

	/*!
	 * Print out information without having to call `snprintf()` first.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_printf
	 * @brief Print a printf()-like formatted string.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * int my_var = 13;
	 * 
	 * napc_printf("Value of my_var is %d", my_var);
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 */
	void libnapc_printf(const char *fmt, ...) LIBNAPC_FN_PRINTFLIKE(1, 2);

	/*!
	 * Temporarily disable output of `napc_puts`, `napc_putc` and `napc_printf`.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_mute
	 * @brief Disable console/serial output.
	 * @version 2.0.0
	 * @note
	 * This functionality is used in the unit test suite of libnapc.
	 * @changelog 2.0.0 initial version
	 * @example
	 * napc_printf("Hello"); // prints Hello
	 * 
	 * napc_mute();
	 * 
	 * napc_printf(" World!"); // this will not be printed
	 * 
	 * napc_unmute();
	 * 
	 * napc_printf(" Earth!"); // prints Earth!
	 */
	void libnapc_mute(void);

	/*!
	 * Re-enable output of `napc_puts`, `napc_putc` and `napc_printf` after a call to `napc_mute`.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_unmute
	 * @brief Enable console/serial output.
	 * @version 2.0.0
	 * @note
	 * This functionality is used in the unit test suite of libnapc.
	 * @changelog 2.0.0 initial version
	 * @example
	 * napc_printf("Hello"); // prints Hello
	 * 
	 * napc_mute();
	 * 
	 * napc_printf(" World!"); // this will not be printed
	 * 
	 * napc_unmute();
	 * 
	 * napc_printf(" Earth!"); // prints Earth!
	 */
	void libnapc_unmute(void);
#endif
