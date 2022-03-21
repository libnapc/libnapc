#include <hw.module/file/_private/_file.h>

napc_size napc_File_getSize(napc__File file) {
	void *element = napc_Pool_getAddress(&PV_napc_fs_handles_pool, file);

	return HAL_napc_File_getSize(element);
}
