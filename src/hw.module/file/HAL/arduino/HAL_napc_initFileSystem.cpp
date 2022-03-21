#if defined(ARDUINO)
	#include <Arduino.h>
	#include <SD.h>

	extern "C" {
		#include <hw.module/file/_private/_file.h>

		void HAL_napc_initFileSystem(void) {
			if (!SD.begin()) {
				PV_NAPC_FILE_WARNING("Failed to initialize SD-Card.");
			} else {
				PV_NAPC_FILE_INFO("Successfully initialized SD-Card.");

				PV_napc_fs_initialized = true;
			}
		}
	}
#endif
