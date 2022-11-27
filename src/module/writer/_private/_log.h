#if !defined(PV_LIBNAPC_MODULE_WRITER_LOG_h)
	#define PV_LIBNAPC_MODULE_WRITER_LOG_h

	#include <libnapc-log/libnapc-log.h>

	#define PV_LIBNAPC_WRITER_ERROR(...) LIBNAPC_LOG_ERROR("libnapc_writer", ##__VA_ARGS__)
#endif
