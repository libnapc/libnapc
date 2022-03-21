#if defined(ARDUINO)
	#include <Arduino.h>
	#include <SD.h>

	extern "C" {
		#include <hw.module/file/_private/_file.h>

		napc_ssize HAL_napc_File_write(void *ptr, const void *data, napc_size data_size) {
			File *fp = (File *)ptr;

			napc_ssize result = fp->write((unsigned char *)data, data_size);

			fp->flush();

			return result;
		}
	}
#endif
