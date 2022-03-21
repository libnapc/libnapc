#if !defined(HAL_NAPC_HW_MODULE_FILE_h)
	#define HAL_NAPC_HW_MODULE_FILE_h

	#include <hw.module/file/file.h>
	#include <napc-panic/napc-panic.h>

	void HAL_napc_initFileSystem(void);
	void HAL_napc_initFileSystemHandlesPool(void);

	bool HAL_napc_File_open(void *ptr, const char *path, const char *mode);

	napc_ssize HAL_napc_File_write(void *ptr, const void *data, napc_size data_size);
	napc_ssize HAL_napc_File_read(void *ptr, void *buffer, napc_size buffer_size);
	napc_size HAL_napc_File_getSize(void *ptr);

	void HAL_napc_File_close(void *ptr);
#endif
