#include <napc.h>

char buffer[5] = {1,2,3,4,5};

void napc_app_setup(const char *platform) {
	NAPC_IGNORE_VALUE(platform);

	napc__Reader reader = napc_Reader_create(buffer, sizeof(buffer));

	napc_Reader_setAccessFailureMode(&reader, NAPC_ACCESS_FAILURE_MODE_PANIC);

	NAPC_IGNORE_VALUE(napc_Reader_readU8(&reader, NULL));
	NAPC_IGNORE_VALUE(napc_Reader_readU8(&reader, NULL));
	NAPC_IGNORE_VALUE(napc_Reader_readU8(&reader, NULL));
	NAPC_IGNORE_VALUE(napc_Reader_readU8(&reader, NULL));
	NAPC_IGNORE_VALUE(napc_Reader_readU8(&reader, NULL));

	napc_printf("crash:\n");
	NAPC_IGNORE_VALUE(napc_Reader_readU8(&reader, NULL));
}

bool napc_app_loop(napc_time uptime) {
	NAPC_IGNORE_VALUE(uptime);

	return false;
}