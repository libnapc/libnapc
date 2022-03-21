#if !defined(PV_NAPC_PANIC_h)
	#define PV_NAPC_PANIC_h

	#include <napc-panic/napc-panic.h>
	#include <napc-panic/HAL/HAL.h>

	#include <napc-time/napc-time.h> // napc_getTimeSinceBoot()
	#include <napc-serial/napc-serial.h> // napc_printf()
	#include <napc-utils/napc-utils.h> // napc_snprintf(), napc_vsnprintf()
#endif
