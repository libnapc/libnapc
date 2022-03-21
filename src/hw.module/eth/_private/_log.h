#if !defined(PV_NAPC_HW_MODULE_ETH_LOG_h)
	#define PV_NAPC_HW_MODULE_ETH_LOG_h

	#include <napc-log/napc-log.h>

	#define PV_NAPC_ETH_VERBOSE(...)  NAPC_LOG_VERBOSE("libnapc_eth", ##__VA_ARGS__)
	#define PV_NAPC_ETH_TRACE(...)    NAPC_LOG_TRACE("libnapc_eth", ##__VA_ARGS__)
	#define PV_NAPC_ETH_DEBUG(...)    NAPC_LOG_DEBUG("libnapc_eth", ##__VA_ARGS__)
	#define PV_NAPC_ETH_INFO(...)     NAPC_LOG_INFO("libnapc_eth", ##__VA_ARGS__)
	#define PV_NAPC_ETH_WARNING(...)  NAPC_LOG_WARNING("libnapc_eth", ##__VA_ARGS__)
	#define PV_NAPC_ETH_ERROR(...)    NAPC_LOG_ERROR("libnapc_eth", ##__VA_ARGS__)
#endif
