#if !defined(PV_LIBNAPC_MODULE_DNS_LOG_h)
	#define PV_LIBNAPC_MODULE_DNS_LOG_h

	#include <libnapc-log/libnapc-log.h>

	#define PV_NAPC_DNS_VERBOSE(...)  LIBNAPC_LOG_VERBOSE("libnapc_dns", ##__VA_ARGS__)
	#define PV_NAPC_DNS_TRACE(...)    LIBNAPC_LOG_TRACE("libnapc_dns", ##__VA_ARGS__)
	#define PV_NAPC_DNS_DEBUG(...)    LIBNAPC_LOG_DEBUG("libnapc_dns", ##__VA_ARGS__)
	#define PV_NAPC_DNS_INFO(...)     LIBNAPC_LOG_INFO("libnapc_dns", ##__VA_ARGS__)
	#define PV_NAPC_DNS_WARNING(...)  LIBNAPC_LOG_WARNING("libnapc_dns", ##__VA_ARGS__)
	#define PV_NAPC_DNS_ERROR(...)    LIBNAPC_LOG_ERROR("libnapc_dns", ##__VA_ARGS__)
#endif
