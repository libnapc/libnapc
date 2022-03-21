#if !defined(PV_NAPC_MODULE_DNS_LOG_h)
	#define PV_NAPC_MODULE_DNS_LOG_h

	#include <napc-log/napc-log.h>

	#define PV_NAPC_DNS_VERBOSE(...)  NAPC_LOG_VERBOSE("libnapc_dns", ##__VA_ARGS__)
	#define PV_NAPC_DNS_TRACE(...)    NAPC_LOG_TRACE("libnapc_dns", ##__VA_ARGS__)
	#define PV_NAPC_DNS_DEBUG(...)    NAPC_LOG_DEBUG("libnapc_dns", ##__VA_ARGS__)
	#define PV_NAPC_DNS_INFO(...)     NAPC_LOG_INFO("libnapc_dns", ##__VA_ARGS__)
	#define PV_NAPC_DNS_WARNING(...)  NAPC_LOG_WARNING("libnapc_dns", ##__VA_ARGS__)
	#define PV_NAPC_DNS_ERROR(...)    NAPC_LOG_ERROR("libnapc_dns", ##__VA_ARGS__)
#endif
