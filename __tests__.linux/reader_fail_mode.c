#include <libnapc.h>

char buffer[5] = {1,2,3,4,5};

int main(int argc, const char **argv) {
	LIBNAPC_IGNORE_VALUE(argc);
	LIBNAPC_IGNORE_VALUE(argv);

	libnapc_init();

	napc__Reader reader = libnapc_Reader_create(buffer, sizeof(buffer));

	libnapc_Reader_setAccessFailureMode(&reader, LIBNAPC_ACCESS_FAILURE_MODE_PANIC);

	LIBNAPC_IGNORE_VALUE(libnapc_Reader_readU8(&reader, NULL));
	LIBNAPC_IGNORE_VALUE(libnapc_Reader_readU8(&reader, NULL));
	LIBNAPC_IGNORE_VALUE(libnapc_Reader_readU8(&reader, NULL));
	LIBNAPC_IGNORE_VALUE(libnapc_Reader_readU8(&reader, NULL));
	LIBNAPC_IGNORE_VALUE(libnapc_Reader_readU8(&reader, NULL));

	libnapc_printf("crash:\n");
	LIBNAPC_IGNORE_VALUE(libnapc_Reader_readU8(&reader, NULL));
}
