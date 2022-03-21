#if !defined(HAL_NAPC_PANIC_h)
	#define HAL_NAPC_PANIC_h

	#include <napc-panic/napc-panic.h>

	void HAL_napc_abort(void) NAPC_FN_NORETURN();
#endif
