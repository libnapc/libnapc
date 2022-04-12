#include <napc.h>

char buffer[5];

void napc_app_setup(const char *platform) {
	NAPC_IGNORE_VALUE(platform);

	napc__NFWriter writer = napc_NFWriter_create(buffer, sizeof(buffer));

	napc_NFWriter_writeU8(&writer, 10);
	napc_NFWriter_writeU8(&writer, 10);
	napc_NFWriter_writeU8(&writer, 10);
	napc_NFWriter_writeU8(&writer, 10);
	napc_NFWriter_writeU8(&writer, 10);

	napc_printf("crash:\n");
	napc_NFWriter_writeU8(&writer, 10);
}

bool napc_app_loop(napc_time uptime) {
	NAPC_IGNORE_VALUE(uptime);

	return false;
}
