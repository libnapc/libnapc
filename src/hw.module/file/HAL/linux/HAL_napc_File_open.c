#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>
	#include <stdio.h> // FILE, fopen(), fileno()
	#include <napc-utils/napc-utils.h> // napc_strlen(), napc_snprintf(), napc_strncpy()

	extern char PV_napc_fs_linuxRootPath[512]; // @global

	bool HAL_napc_File_open(void *ptr, const char *path, const char *mode) {
		char realpath[1024];

		if (napc_strlen(PV_napc_fs_linuxRootPath)) {
			napc_snprintf(realpath, sizeof(realpath), "%s/%s", PV_napc_fs_linuxRootPath, path);
		} else {
			napc_strncpy(realpath, path, sizeof(realpath));
		}

		FILE *fp = fopen(realpath, mode);

		if (!fp) {
			return false;
		}

		FILE **tmp = ptr;
		*tmp = fp;

		return true;
	}
#endif
