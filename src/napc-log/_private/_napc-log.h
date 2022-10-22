#if !defined(PV_NAPC_LOG_h)
	#define PV_NAPC_LOG_h

	#include <napc-log/napc-log.h>
	#include <napc-log/HAL/HAL.h>

	#include <napc-core/napc-core.h> // napc_getFreeMemory()
	#include <napc-time/napc-time.h> // napc_getTimeSinceBoot()
	#include <napc-utils/napc-utils.h> // napc_snprintf()
	#include <napc-serial/napc-serial.h> // napc_printf()

	extern napc_logHandlerFunction PV_napc_log_handler_array[5]; // @global
	extern void *PV_napc_log_handler_context_array[5]; // @global
	extern bool PV_napc_log_colorful_output; // @global
#endif
