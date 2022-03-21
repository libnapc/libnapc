#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>
	#include <stdio.h> // fwrite()

	napc_ssize HAL_napc_File_write(void *ptr, const void *data, napc_size data_size) {
		FILE **fp = ptr;

		return fwrite(data, 1, data_size, *fp);
	}
#endif
