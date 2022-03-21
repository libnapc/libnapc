#if defined(ARDUINO)
	#include <Arduino.h>
	#include <SD.h>

	extern "C" {
		#include <hw.module/file/_private/_file.h>

		napc_size HAL_napc_File_getSize(void *ptr) {
			File *fp = (File *)ptr;

			return fp->size();
		}
	}
#endif
