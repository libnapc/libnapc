#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>
	#include <stdio.h> // FILE, fopen(), fileno()
	#include <napc-utils/napc-utils.h> // napc_snprintf()

	bool HAL_napc_File_open(void *ptr, const char *path, const char *mode) {
		char realpath[512];

		const char *FS_ROOT_DIR = getenv("NAPC_FS_ROOT_DIR");

		if (!FS_ROOT_DIR) {
			FS_ROOT_DIR = "";
		}

		napc_snprintf(realpath, sizeof(realpath), "%s%s", FS_ROOT_DIR, path);

		FILE *fp = fopen(realpath, mode);

		if (!fp) {
			return false;
		}

		FILE **tmp = ptr;
		*tmp = fp;

		return true;
	}
#endif
