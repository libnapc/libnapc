#if !defined(NAPC_CORE_h)
	#define NAPC_CORE_h

	#include <libnapc.h>

	#include <napc-panic/napc-panic.h>

	extern void napc_setup(const char *platform);
	extern bool napc_loop(napc_time uptime);

	/*!
	 * @name napc_getUptime
	 * @brief Get uptime in seconds.
	 * @version 1.0.0
	 * @description
	 * Get the uptime in seconds.
	 * @return Returns the number of seconds that have passed since boot.
	 * @flags hw
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_time uptime = napc_getUptime();
	 * 
	 * napc_printf("I'm up since %" NAPC_TIME_PRINTF " seconds", uptime);
	 */
	napc_time napc_getUptime(void) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_getFreeMemory
	 * @brief Get free memory.
	 * @version 1.0.0
	 * @description
	 * Returns the number of free bytes (on the stack) available.
	 * @flags hw
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_size napc_getFreeMemory(void) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name NAPC_ASSERT
	 * @module Core
	 * @brief Make an assertion.
	 * @version 1.0.0
	 * @description
	 * Assert an expression.
	 * @param bool expr Expression to assert.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u8 var = 13;
	 * 
	 * NAPC_ASSERT(var == 13);
	 */
	#define NAPC_ASSERT(expr)                    \
		do {                                     \
			if (!(expr)) {                       \
				NAPC_PANIC("Assertion failed."); \
			}                                    \
		} while(false)
#endif
