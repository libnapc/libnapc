#if !defined(PV_NAPC_MODULE_RINGBUFFER_LOG_h)
	#define PV_NAPC_MODULE_RINGBUFFER_LOG_h

	#include <libnapc-log/libnapc-log.h>

	#define PV_NAPC_RINGBUFFER_VERBOSE(...)  LIBNAPC_LOG_VERBOSE("libnapc_ring-buffer", ##__VA_ARGS__)
	#define PV_NAPC_RINGBUFFER_TRACE(...)    LIBNAPC_LOG_TRACE("libnapc_ring-buffer", ##__VA_ARGS__)
	#define PV_NAPC_RINGBUFFER_DEBUG(...)    LIBNAPC_LOG_DEBUG("libnapc_ring-buffer", ##__VA_ARGS__)
	#define PV_NAPC_RINGBUFFER_INFO(...)     LIBNAPC_LOG_INFO("libnapc_ring-buffer", ##__VA_ARGS__)
	#define PV_NAPC_RINGBUFFER_WARNING(...)  LIBNAPC_LOG_WARNING("libnapc_ring-buffer", ##__VA_ARGS__)
	#define PV_NAPC_RINGBUFFER_ERROR(...)    LIBNAPC_LOG_ERROR("libnapc_ring-buffer", ##__VA_ARGS__)
#endif
