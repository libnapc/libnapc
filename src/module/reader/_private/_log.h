#if !defined(PV_LIBNAPC_MODULE_READER_LOG_h)
	#define PV_LIBNAPC_MODULE_READER_LOG_h

	#include <libnapc-log/libnapc-log.h>

	#define PV_LIBNAPC_READER_ERROR(...) LIBNAPC_LOG_ERROR("libnapc_reader", ##__VA_ARGS__)
#endif
