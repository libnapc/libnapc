#if !defined(PV_NAPC_MODULE_READER_LOG_h)
	#define PV_NAPC_MODULE_READER_LOG_h

	#include <libnapc-log/libnapc-log.h>

	#define PV_NAPC_READER_VERBOSE(...)  LIBNAPC_LOG_VERBOSE("libnapc_reader", ##__VA_ARGS__)
	#define PV_NAPC_READER_TRACE(...)    LIBNAPC_LOG_TRACE("libnapc_reader", ##__VA_ARGS__)
	#define PV_NAPC_READER_DEBUG(...)    LIBNAPC_LOG_DEBUG("libnapc_reader", ##__VA_ARGS__)
	#define PV_NAPC_READER_INFO(...)     LIBNAPC_LOG_INFO("libnapc_reader", ##__VA_ARGS__)
	#define PV_NAPC_READER_WARNING(...)  LIBNAPC_LOG_WARNING("libnapc_reader", ##__VA_ARGS__)
	#define PV_NAPC_READER_ERROR(...)    LIBNAPC_LOG_ERROR("libnapc_reader", ##__VA_ARGS__)
#endif
