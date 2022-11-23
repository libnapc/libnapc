#if !defined(NAPC_SERIAL_h)
	#define NAPC_SERIAL_h

	#include <libnapc-internal.h>

	/*!
	 * @name napc_puts
	 * @brief Print a string to console/serial.
	 * @version 1.0.0
	 * @description Output a string via console or serial.
	 * @flags hw
	 * @param str The string to be printed.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_puts("Hello World!");
	 */
	void libnapc_puts(const char *str);

	/*!
	 * @name napc_putc
	 * @brief Print a character to console/serial.
	 * @version 1.0.0
	 * @description Output a single character via console or serial.
	 * @flags hw
	 * @param ch The character to be printed.
	 * @changelog 1.0.0 17.02.2022 initial version
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
	 * @name napc_printf
	 * @brief Print a printf()-like formatted string.
	 * @version 1.0.0
	 * @description
	 * Print out information without having to call `snprintf()` first.
	 * @flags smem
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * int my_var = 13;
	 * 
	 * napc_printf("Value of my_var is %d", my_var);
	 * @param fmt printf()-like format string.
	 * @param ... Values to incorporate into string.
	 */
	void napc_printf(const char *fmt, ...) NAPC_FN_PRINTFLIKE(1, 2);

	/*!
	 * @name napc_mute
	 * @brief Disable console/serial output.
	 * @version 1.0.0
	 * @description
	 * Temporarily disable output of `napc_puts`, `napc_putc` and `napc_printf`.
	 * @notes
	 * This functionality is used in the unit test suite of libnapc.
	 * @changelog 1.0.0 17.02.2022 initial version
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
	void napc_mute(void);

	/*!
	 * @name napc_unmute
	 * @brief Enable console/serial output.
	 * @version 1.0.0
	 * @description
	 * Re-enable output of `napc_puts`, `napc_putc` and `napc_printf` after a call to `napc_mute`.
	 * @notes
	 * This functionality is used in the unit test suite of libnapc.
	 * @changelog 1.0.0 17.02.2022 initial version
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
	void napc_unmute(void);
#endif
