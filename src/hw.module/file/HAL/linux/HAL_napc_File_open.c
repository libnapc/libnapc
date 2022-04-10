#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>
	#include <stdio.h> // FILE, fopen(), fileno()
	#include <napc-utils/napc-utils.h> // napc_snprintf()

	bool HAL_napc_File_open(void *ptr, const char *path, const char *mode) {
		char realpath[512];

		const char *FILE_ROOT_PATH = getenv("NAPC_FILE_ROOT_PATH");

		if (!FILE_ROOT_PATH) {
			FILE_ROOT_PATH = "";
		}

		napc_snprintf(realpath, sizeof(realpath), "%s%s", FILE_ROOT_PATH, path);

		FILE *fp = fopen(realpath, mode);

		if (!fp) {
			return false;
		}

		FILE **tmp = ptr;
		*tmp = fp;

		return true;
	}
#endif
