#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>
	#include <stdio.h> // FILE, fopen()

	void HAL_napc_File_close(void *ptr) {
		FILE **fp = ptr;

		fclose(*fp);
	}
#endif
