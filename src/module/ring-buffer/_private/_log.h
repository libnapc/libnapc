#if !defined(PV_LIBNAPC_MODULE_RINGBUFFER_LOG_h)
	#define PV_LIBNAPC_MODULE_RINGBUFFER_LOG_h

	#include <libnapc-log/libnapc-log.h>

	#define PV_LIBNAPC_RINGBUFFER_ERROR(...) LIBNAPC_LOG_ERROR("libnapc_ring-buffer", ##__VA_ARGS__)
#endif
