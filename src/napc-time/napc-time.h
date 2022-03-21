#if !defined(NAPC_TIME_h)
	#define NAPC_TIME_h

	#include <libnapc.h>

	/*!
	 * @name napc_getTimeSinceBoot
	 * @brief Get time since boot.
	 * @version 1.0.0
	 * @description
	 * Returns the number of milliseconds that have passed since boot.
	 * @warning
	 * The value returned by this function will overflow at some point in time.
	 * @flags hw
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_time napc_getTimeSinceBoot(void) NAPC_FN_WARNUNUSED_RET();
#endif
