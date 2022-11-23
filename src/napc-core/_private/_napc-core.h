#if !defined(PV_NAPC_CORE_h)
	#define PV_NAPC_CORE_h

	#include <HAL/HAL.h>

	// PV_napc_getDefaultAccessFailureMode defined in napc-core.h
	// PV_napc_validateAccessFailureMode defined in napc-core.h
	#include <napc-core/napc-core.h>

	#include <napc-serial/napc-serial.h> // napc_printf()
	#include <napc-time/napc-time.h> // libnapc_getTimeSinceBoot()
	#include <napc-delay/napc-delay.h> // napc_delay()
	#include <napc-utils/napc-utils.h> // libnapc_streqli()

	extern napc__AccessFailureMode PV_napc_default_access_failure_mode; // @global
#endif
