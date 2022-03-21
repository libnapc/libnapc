#if !defined(PV_NAPC_MODULE_WRITER_LOG_h)
	#define PV_NAPC_MODULE_WRITER_LOG_h

	#include <napc-log/napc-log.h>

	#define PV_NAPC_WRITER_VERBOSE(...)  NAPC_LOG_VERBOSE("libnapc_writer", ##__VA_ARGS__)
	#define PV_NAPC_WRITER_TRACE(...)    NAPC_LOG_TRACE("libnapc_writer", ##__VA_ARGS__)
	#define PV_NAPC_WRITER_DEBUG(...)    NAPC_LOG_DEBUG("libnapc_writer", ##__VA_ARGS__)
	#define PV_NAPC_WRITER_INFO(...)     NAPC_LOG_INFO("libnapc_writer", ##__VA_ARGS__)
	#define PV_NAPC_WRITER_WARNING(...)  NAPC_LOG_WARNING("libnapc_writer", ##__VA_ARGS__)
	#define PV_NAPC_WRITER_ERROR(...)    NAPC_LOG_ERROR("libnapc_writer", ##__VA_ARGS__)
#endif
