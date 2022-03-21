#include <napc.h>

void napc_runAllTests(void);

void napc_app_setup(const char *platform) {
	napc_printf("Platform is %s\n", platform);
	napc_printf("libnapc version is %s\n", napc_version());

	napc_runAllTests();
}

bool napc_app_loop(napc_time uptime) {
	NAPC_IGNORE_VALUE(uptime);

	return false;
}
