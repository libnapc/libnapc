#if !defined(LIBNAPC_TIME_h)
	#define LIBNAPC_TIME_h

	#include <libnapc-internal.h>

	/*!
	 * Return number of milliseconds that have passed since boot.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_getTimeSinceBoot
	 * @brief Get time since boot.
	 * @version 2.0.0
	 * @warning
	 * The value returned by this function will overflow at some point in time.
	 * @changelog 2.0.0 initial version
	 */
	libnapc_time libnapc_getTimeSinceBoot(void) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * Return number of microseconds that have passed since boot.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_getTimeSinceBootHR
	 * @brief Get time since boot in microseconds.
	 * @version 2.0.0
	 * @warning
	 * The value returned by this function will overflow at some point in time.
	 * @changelog 2.0.0 initial version
	 */
	libnapc_time libnapc_getTimeSinceBootHR(void) NAPC_FN_WARNUNUSED_RET();
#endif
