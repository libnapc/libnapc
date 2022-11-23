// needs doc-block fixing
#if !defined(LIBNAPC_TIME_h)
	#define LIBNAPC_TIME_h

	#include <libnapc-internal.h>

	/*!
	 * @name napc_getTimeSinceBoot
	 * @brief Get time since boot.
	 * @version 1.0.0
	 * @description
	 * Return number of milliseconds that have passed since boot.
	 * @warning
	 * The value returned by this function will overflow at some point in time.
	 * @flags hw
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_time libnapc_getTimeSinceBoot(void) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_getTimeSinceBootHR
	 * @brief Get time since boot in microseconds.
	 * @version 2.0.0
	 * @description
	 * Return number of microseconds that have passed since boot.
	 * @warning
	 * The value returned by this function will overflow at some point in time.
	 * @flags hw
	 * @changelog 2.0.0 21.10.2022 initial version
	 */
	napc_time libnapc_getTimeSinceBootHR(void) NAPC_FN_WARNUNUSED_RET();
#endif
