#if !defined(PV_NAPC_HW_MODULE_FILE_LOG_h)
	#define PV_NAPC_HW_MODULE_FILE_LOG_h

	#include <napc-log/napc-log.h>

	#define PV_NAPC_FILE_VERBOSE(...)  NAPC_LOG_VERBOSE("libnapc_file", ##__VA_ARGS__)
	#define PV_NAPC_FILE_TRACE(...)    NAPC_LOG_TRACE("libnapc_file", ##__VA_ARGS__)
	#define PV_NAPC_FILE_DEBUG(...)    NAPC_LOG_DEBUG("libnapc_file", ##__VA_ARGS__)
	#define PV_NAPC_FILE_INFO(...)     NAPC_LOG_INFO("libnapc_file", ##__VA_ARGS__)
	#define PV_NAPC_FILE_WARNING(...)  NAPC_LOG_WARNING("libnapc_file", ##__VA_ARGS__)
	#define PV_NAPC_FILE_ERROR(...)    NAPC_LOG_ERROR("libnapc_file", ##__VA_ARGS__)
#endif
