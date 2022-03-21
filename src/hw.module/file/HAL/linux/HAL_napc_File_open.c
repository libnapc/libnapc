#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>
	#include <stdio.h> // FILE, fopen(), fileno()

	bool HAL_napc_File_open(void *ptr, const char *path, const char *mode) {
		FILE *fp = fopen(path, mode);

		if (!fp) {
			return false;
		}

		FILE **tmp = ptr;
		*tmp = fp;

		return true;
	}
#endif
