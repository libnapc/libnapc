#if defined(ARDUINO)
	#include <Arduino.h>
	#include <SD.h>

	extern "C" {
		#include <hw.module/file/_private/_file.h>

		static File _file_handles[5]; // @static

		void HAL_napc_initFileSystemHandlesPool(void) {
			napc_Pool_init(
				&PV_napc_fs_handles_pool,
				"File",
				_file_handles,
				sizeof(_file_handles) / sizeof(File),
				sizeof(File)
			);
		}
	}
#endif
