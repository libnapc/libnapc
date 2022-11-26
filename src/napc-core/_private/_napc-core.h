#if !defined(PV_LIBNAPC_CORE_h)
	#define PV_LIBNAPC_CORE_h

	#include <HAL/HAL.h>

	// PV_libnapc_getDefaultAccessFailureMode defined in napc-core.h
	// PV_napc_validateAccessFailureMode defined in napc-core.h
	#include <napc-core/napc-core.h>

	#include <napc-serial/napc-serial.h> // napc_printf()
	#include <napc-time/napc-time.h> // libnapc_getTimeSinceBoot()
	#include <napc-delay/napc-delay.h> // libnapc_delay()
	#include <napc-utils/napc-utils.h> // libnapc_streqli()

	extern libnapc__AccessFailureMode PV_libnapc_default_access_failure_mode; // @global
#endif
