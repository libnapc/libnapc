#if !defined(PV_NAPC_MODULE_WRITER_LOG_h)
	#define PV_NAPC_MODULE_WRITER_LOG_h

	#include <libnapc-log/libnapc-log.h>

	#define PV_NAPC_WRITER_VERBOSE(...)  LIBNAPC_LOG_VERBOSE("libnapc_writer", ##__VA_ARGS__)
	#define PV_NAPC_WRITER_TRACE(...)    LIBNAPC_LOG_TRACE("libnapc_writer", ##__VA_ARGS__)
	#define PV_NAPC_WRITER_DEBUG(...)    LIBNAPC_LOG_DEBUG("libnapc_writer", ##__VA_ARGS__)
	#define PV_NAPC_WRITER_INFO(...)     LIBNAPC_LOG_INFO("libnapc_writer", ##__VA_ARGS__)
	#define PV_NAPC_WRITER_WARNING(...)  LIBNAPC_LOG_WARNING("libnapc_writer", ##__VA_ARGS__)
	#define PV_NAPC_WRITER_ERROR(...)    LIBNAPC_LOG_ERROR("libnapc_writer", ##__VA_ARGS__)
#endif
