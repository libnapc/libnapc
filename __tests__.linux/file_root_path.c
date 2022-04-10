#include <napc.h>

char file_contents[1024];

void napc_app_setup(const char *platform) {
	NAPC_IGNORE_VALUE(platform);

	if (napc_fs_readFileCString("test.txt", file_contents, sizeof(file_contents))) {
		napc_printf("contents_of_file:%s\n", file_contents);
	}
}

bool napc_app_loop(napc_time uptime) {
	NAPC_IGNORE_VALUE(uptime);

	return false;
}
