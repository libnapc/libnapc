#include <napc.h>
void libnapc_callBootFunctions(void);

char buffer[5];

int main(int argc, const char **argv) {
	NAPC_IGNORE_VALUE(argc);
	NAPC_IGNORE_VALUE(argv);

	libnapc_callBootFunctions();

	napc__Writer writer = napc_Writer_create(buffer, sizeof(buffer));

	napc_Writer_setAccessFailureMode(&writer, NAPC_ACCESS_FAILURE_MODE_PANIC);

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
