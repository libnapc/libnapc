#if !defined(PV_NAPC_HW_MODULE_FS_LOG_h)
	#define PV_NAPC_HW_MODULE_FS_LOG_h

	#include <napc-log/napc-log.h>

	#define PV_NAPC_FS_VERBOSE(...)  NAPC_LOG_VERBOSE("libnapc_fs", ##__VA_ARGS__)
	#define PV_NAPC_FS_TRACE(...)    NAPC_LOG_TRACE("libnapc_fs", ##__VA_ARGS__)
	#define PV_NAPC_FS_DEBUG(...)    NAPC_LOG_DEBUG("libnapc_fs", ##__VA_ARGS__)
	#define PV_NAPC_FS_INFO(...)     NAPC_LOG_INFO("libnapc_fs", ##__VA_ARGS__)
	#define PV_NAPC_FS_WARNING(...)  NAPC_LOG_WARNING("libnapc_fs", ##__VA_ARGS__)
	#define PV_NAPC_FS_ERROR(...)    NAPC_LOG_ERROR("libnapc_fs", ##__VA_ARGS__)
#endif
