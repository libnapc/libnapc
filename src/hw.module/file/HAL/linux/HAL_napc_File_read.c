#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>
	#include <stdio.h> // fread()

	napc_ssize HAL_napc_File_read(void *ptr, void *buffer, napc_size buffer_size) {
		FILE **fp = ptr;

		return fread(buffer, 1, buffer_size, *fp);
	}
#endif
