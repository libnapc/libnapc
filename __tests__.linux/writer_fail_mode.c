#include <napc.h>

char buffer[5];

void napc_app_setup(const char *platform) {
	NAPC_IGNORE_VALUE(platform);

	napc__Writer writer = napc_Writer_create(buffer, sizeof(buffer));

	napc_Writer_setNoFailMode(&writer, true);

	napc_Writer_writeU8(&writer, 10);
	napc_Writer_writeU8(&writer, 10);
	napc_Writer_writeU8(&writer, 10);
	napc_Writer_writeU8(&writer, 10);
	napc_Writer_writeU8(&writer, 10);

	napc_printf("crash:\n");
	napc_Writer_writeU8(&writer, 10);
}

bool napc_app_loop(napc_time uptime) {
	NAPC_IGNORE_VALUE(uptime);

	return false;
}
