#include <libnapc.h>

char buffer[5];

int main(int argc, const char **argv) {
	LIBNAPC_IGNORE_VALUE(argc);
	LIBNAPC_IGNORE_VALUE(argv);

	libnapc_init();

	napc__Writer writer = libnapc_Writer_create(buffer, sizeof(buffer));

	libnapc_Writer_setAccessFailureMode(&writer, LIBNAPC_ACCESS_FAILURE_MODE_PANIC);

	libnapc_Writer_writeU8(&writer, 10);
	libnapc_Writer_writeU8(&writer, 10);
	libnapc_Writer_writeU8(&writer, 10);
	libnapc_Writer_writeU8(&writer, 10);
	libnapc_Writer_writeU8(&writer, 10);

	libnapc_printf("crash:\n");
	libnapc_Writer_writeU8(&writer, 10);
}
