#if !defined(NAPC_MODULE_APP_h)
	#define NAPC_MODULE_APP_h

	#include <libnapc.h>

	extern void napc_app_setup(const char *platform);
	extern bool napc_app_loop(napc_time uptime);
#endif
