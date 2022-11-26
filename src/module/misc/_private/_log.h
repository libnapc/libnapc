#if !defined(PV_NAPC_MODULE_MISC_LOG_h)
	#define PV_NAPC_MODULE_MISC_LOG_h

	#include <napc-log/napc-log.h>

	#define PV_NAPC_MISC_VERBOSE(...)  LIBNAPC_LOG_VERBOSE("libnapc_misc", ##__VA_ARGS__)
	#define PV_NAPC_MISC_TRACE(...)    LIBNAPC_LOG_TRACE("libnapc_misc", ##__VA_ARGS__)
	#define PV_NAPC_MISC_DEBUG(...)    LIBNAPC_LOG_DEBUG("libnapc_misc", ##__VA_ARGS__)
	#define PV_NAPC_MISC_INFO(...)     LIBNAPC_LOG_INFO("libnapc_misc", ##__VA_ARGS__)
	#define PV_NAPC_MISC_WARNING(...)  LIBNAPC_LOG_WARNING("libnapc_misc", ##__VA_ARGS__)
	#define PV_NAPC_MISC_ERROR(...)    LIBNAPC_LOG_ERROR("libnapc_misc", ##__VA_ARGS__)
#endif
