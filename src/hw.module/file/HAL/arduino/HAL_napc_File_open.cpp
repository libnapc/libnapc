#if defined(ARDUINO)
	#include <Arduino.h>
	#include <SD.h>

	extern "C" {
		#include <hw.module/file/_private/_file.h>

		extern napc__Pool PV_napc_files_pool_arduino; // @global

		bool HAL_napc_File_open(void *ptr, const char *path, const char *mode) {
			File fp = SD.open(path);

			if (!fp) {
				return false;
			}

			File *tmp = (File *)ptr;
			*tmp = fp;

			return true;
		}
	}
#endif
