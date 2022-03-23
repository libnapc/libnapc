#include <hw.module/file/_private/_file.h>

void napc_File_close(napc__File file) {
	void *element = napc_Pool_getAddress(&PV_napc_fs_handles_pool, file);

	HAL_napc_File_close(element);

	napc_Pool_releaseElement(&PV_napc_fs_handles_pool, file);
}
