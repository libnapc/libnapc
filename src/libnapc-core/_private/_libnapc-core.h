#if !defined(PV_LIBNAPC_CORE_h)
	#define PV_LIBNAPC_CORE_h

	#include <HAL/HAL.h>

	// PV_libnapc_getDefaultAccessFailureMode defined in libnapc-core.h
	// PV_libnapc_validateAccessFailureMode defined in libnapc-core.h
	#include <libnapc-core/libnapc-core.h>

	#include <libnapc-serial/libnapc-serial.h> // libnapc_printf()
	#include <libnapc-time/libnapc-time.h> // libnapc_getTimeSinceBoot()
	#include <libnapc-delay/libnapc-delay.h> // libnapc_delay()
	#include <libnapc-utils/libnapc-utils.h> // libnapc_streqli()

	extern libnapc__AccessFailureMode PV_libnapc_default_access_failure_mode; // @global
#endif
