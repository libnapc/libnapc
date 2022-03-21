#if !defined(PV_NAPC_MODULE_MISC_LOG_h)
	#define PV_NAPC_MODULE_MISC_LOG_h

	#include <napc-log/napc-log.h>

	#define PV_NAPC_MISC_VERBOSE(...)  NAPC_LOG_VERBOSE("libnapc_misc", ##__VA_ARGS__)
	#define PV_NAPC_MISC_TRACE(...)    NAPC_LOG_TRACE("libnapc_misc", ##__VA_ARGS__)
	#define PV_NAPC_MISC_DEBUG(...)    NAPC_LOG_DEBUG("libnapc_misc", ##__VA_ARGS__)
	#define PV_NAPC_MISC_INFO(...)     NAPC_LOG_INFO("libnapc_misc", ##__VA_ARGS__)
	#define PV_NAPC_MISC_WARNING(...)  NAPC_LOG_WARNING("libnapc_misc", ##__VA_ARGS__)
	#define PV_NAPC_MISC_ERROR(...)    NAPC_LOG_ERROR("libnapc_misc", ##__VA_ARGS__)
#endif
