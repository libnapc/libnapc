#include <module/app/_private/_app.h>

void napc_app_setup(const char *platform) NAPC_FN_WEAK();
void napc_setup(const char *platform) NAPC_FN_WEAK();

void napc_app_setup(const char *platform) {
	napc_printf("napc_app_setup() is not defined.\n");
}

void napc_setup(const char *platform) {
	napc_app_setup(platform);
}
