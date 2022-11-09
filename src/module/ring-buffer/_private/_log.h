#if !defined(PV_NAPC_MODULE_RINGBUFFER_LOG_h)
	#define PV_NAPC_MODULE_RINGBUFFER_LOG_h

	#include <napc-log/napc-log.h>

	#define PV_NAPC_RINGBUFFER_VERBOSE(...)  NAPC_LOG_VERBOSE("libnapc_ring-buffer", ##__VA_ARGS__)
	#define PV_NAPC_RINGBUFFER_TRACE(...)    NAPC_LOG_TRACE("libnapc_ring-buffer", ##__VA_ARGS__)
	#define PV_NAPC_RINGBUFFER_DEBUG(...)    NAPC_LOG_DEBUG("libnapc_ring-buffer", ##__VA_ARGS__)
	#define PV_NAPC_RINGBUFFER_INFO(...)     NAPC_LOG_INFO("libnapc_ring-buffer", ##__VA_ARGS__)
	#define PV_NAPC_RINGBUFFER_WARNING(...)  NAPC_LOG_WARNING("libnapc_ring-buffer", ##__VA_ARGS__)
	#define PV_NAPC_RINGBUFFER_ERROR(...)    NAPC_LOG_ERROR("libnapc_ring-buffer", ##__VA_ARGS__)
#endif
