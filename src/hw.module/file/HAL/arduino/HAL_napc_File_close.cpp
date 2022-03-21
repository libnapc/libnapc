#if defined(ARDUINO)
	#include <Arduino.h>
	#include <SD.h>

	extern "C" {
		#include <hw.module/file/_private/_file.h>

		void HAL_napc_File_close(void *ptr) {
			File *fp = (File *)ptr;

			fp->close();
		}
	}
#endif
