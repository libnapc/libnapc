#if !defined(HAL_NAPC_CORE_h)
	#define HAL_NAPC_CORE_h

	#include <napc-core/napc-core.h>

	void HAL_napc_loopYieldCPU(void);

	napc_size HAL_napc_getFreeMemory(void) NAPC_FN_WARNUNUSED_RET();
#endif
