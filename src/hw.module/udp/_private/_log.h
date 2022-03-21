#if !defined(PV_NAPC_HW_MODULE_UDP_LOG_h)
	#define PV_NAPC_HW_MODULE_UDP_LOG_h

	#include <napc-log/napc-log.h>

	#define PV_NAPC_UDP_VERBOSE(...)  NAPC_LOG_VERBOSE("libnapc_udp", ##__VA_ARGS__)
	#define PV_NAPC_UDP_TRACE(...)    NAPC_LOG_TRACE("libnapc_udp", ##__VA_ARGS__)
	#define PV_NAPC_UDP_DEBUG(...)    NAPC_LOG_DEBUG("libnapc_udp", ##__VA_ARGS__)
	#define PV_NAPC_UDP_INFO(...)     NAPC_LOG_INFO("libnapc_udp", ##__VA_ARGS__)
	#define PV_NAPC_UDP_WARNING(...)  NAPC_LOG_WARNING("libnapc_udp", ##__VA_ARGS__)
	#define PV_NAPC_UDP_ERROR(...)    NAPC_LOG_ERROR("libnapc_udp", ##__VA_ARGS__)
#endif
