#if !defined(PV_LIBNAPC_LOG_h)
	#define PV_LIBNAPC_LOG_h

	#include <libnapc-log/libnapc-log.h>
	#include <libnapc-log/HAL/HAL.h>

	#include <libnapc-core/libnapc-core.h> // libnapc_getFreeMemory()
	#include <libnapc-time/libnapc-time.h> // libnapc_getTimeSinceBoot()
	#include <libnapc-utils/libnapc-utils.h> // libnapc_snprintf()
	#include <libnapc-serial/libnapc-serial.h> // libnapc_printf()

	extern libnapc_logHandlerFunction PV_libnapc_log_handler_array[5]; // @global
	extern void *PV_libnapc_log_handler_context_array[5]; // @global
	extern bool PV_libnapc_log_colorful_output; // @global
#endif
