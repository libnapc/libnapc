#if !defined(PV_LIBNAPC_MODULE_MISC_LOG_h)
	#define PV_LIBNAPC_MODULE_MISC_LOG_h

	#include <libnapc-log/libnapc-log.h>

	#define PV_LIBNAPC_MISC_VERBOSE(...) LIBNAPC_LOG_VERBOSE("libnapc_misc", ##__VA_ARGS__)
	#define PV_LIBNAPC_MISC_ERROR(...) LIBNAPC_LOG_ERROR("libnapc_misc", ##__VA_ARGS__)
#endif
