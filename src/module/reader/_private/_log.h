#if !defined(PV_NAPC_MODULE_READER_LOG_h)
	#define PV_NAPC_MODULE_READER_LOG_h

	#include <napc-log/napc-log.h>

	#define PV_NAPC_READER_VERBOSE(...)  NAPC_LOG_VERBOSE("libnapc_reader", ##__VA_ARGS__)
	#define PV_NAPC_READER_TRACE(...)    NAPC_LOG_TRACE("libnapc_reader", ##__VA_ARGS__)
	#define PV_NAPC_READER_DEBUG(...)    NAPC_LOG_DEBUG("libnapc_reader", ##__VA_ARGS__)
	#define PV_NAPC_READER_INFO(...)     NAPC_LOG_INFO("libnapc_reader", ##__VA_ARGS__)
	#define PV_NAPC_READER_WARNING(...)  NAPC_LOG_WARNING("libnapc_reader", ##__VA_ARGS__)
	#define PV_NAPC_READER_ERROR(...)    NAPC_LOG_ERROR("libnapc_reader", ##__VA_ARGS__)
#endif
