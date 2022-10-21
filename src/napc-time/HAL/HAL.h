#if !defined(HAL_NAPC_TIME_h)
	#define HAL_NAPC_TIME_h

	#include <napc-time/napc-time.h>

	void HAL_napc_initTime(void);
	napc_time HAL_napc_getTimeSinceBoot(bool high_res);
#endif
