#include <libnapc.h>

char buffer[5] = {1,2,3,4,5};

int main(int argc, const char **argv) {
	NAPC_IGNORE_VALUE(argc);
	NAPC_IGNORE_VALUE(argv);

	libnapc_init();

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
