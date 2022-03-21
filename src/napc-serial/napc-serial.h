#if !defined(NAPC_SERIAL_h)
	#define NAPC_SERIAL_h

	#include <libnapc.h>

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
	void napc_puts(const char *str);

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
	void napc_putc(char ch);

	/*!
	 * @name napc_printf
	 * @brief Print a printf()-like formatted string.
	 * @version 1.0.0
	 * @description
	 * Provides a convient way to print out information without having the need to call `snprintf()` first.
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
	 * @rationale
	 * When running unit tests we are not particularly interested in the output
	 * the code generated. We much rather have a single output that says
	 * test passed or failed.
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
