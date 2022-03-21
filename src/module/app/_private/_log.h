#if !defined(PV_NAPC_MODULE_APP_LOG_h)
	#define PV_NAPC_MODULE_APP_LOG_h

	#include <napc-log/napc-log.h>
	#include <napc-panic/napc-panic.h>

	#define PV_NAPC_APP_VERBOSE(...)  NAPC_LOG_VERBOSE("libnapc_app", ##__VA_ARGS__)
	#define PV_NAPC_APP_TRACE(...)    NAPC_LOG_TRACE("libnapc_app", ##__VA_ARGS__)
	#define PV_NAPC_APP_DEBUG(...)    NAPC_LOG_DEBUG("libnapc_app", ##__VA_ARGS__)
	#define PV_NAPC_APP_INFO(...)     NAPC_LOG_INFO("libnapc_app", ##__VA_ARGS__)
	#define PV_NAPC_APP_WARNING(...)  NAPC_LOG_WARNING("libnapc_app", ##__VA_ARGS__)
	#define PV_NAPC_APP_ERROR(...)    NAPC_LOG_ERROR("libnapc_app", ##__VA_ARGS__)
#endif
