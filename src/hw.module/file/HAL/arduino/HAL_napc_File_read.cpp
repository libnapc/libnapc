#if defined(ARDUINO)
	#include <Arduino.h>
	#include <SD.h>

	extern "C" {
		#include <hw.module/file/_private/_file.h>

		napc_ssize HAL_napc_File_read(void *ptr, void *buffer, napc_size buffer_size) {
			File *fp = (File *)ptr;

			return fp->read(buffer, buffer_size);
		}
	}
#endif
