#include <libnapc.h>

char buffer[5];

int main(int argc, const char **argv) {
	LIBNAPC_IGNORE_VALUE(argc);
	LIBNAPC_IGNORE_VALUE(argv);

	libnapc_init();

	napc__Writer writer = napc_Writer_create(buffer, sizeof(buffer));

	napc_Writer_setAccessFailureMode(&writer, LIBNAPC_ACCESS_FAILURE_MODE_PANIC);

	napc_Writer_writeU8(&writer, 10);
	napc_Writer_writeU8(&writer, 10);
	napc_Writer_writeU8(&writer, 10);
	napc_Writer_writeU8(&writer, 10);
	napc_Writer_writeU8(&writer, 10);

	libnapc_printf("crash:\n");
	napc_Writer_writeU8(&writer, 10);
}
