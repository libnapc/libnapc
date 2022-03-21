#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>
	#include <stdio.h> // FILE

	static FILE *_file_handles[5]; // @static

	void HAL_napc_initFileSystemHandlesPool(void) {
		napc_Pool_init(
			&PV_napc_fs_handles_pool,
			"File",
			_file_handles,
			sizeof(_file_handles) / sizeof(FILE *),
			sizeof(FILE *)
		);
	}
#endif
