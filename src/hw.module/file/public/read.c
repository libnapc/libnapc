#include <hw.module/file/_private/_file.h>

napc_ssize napc_File_read(napc__File file, void *buffer, napc_size buffer_size) {
	void *element = napc_Pool_getAddress(&PV_napc_fs_handles_pool, file);

	napc_ssize ret = HAL_napc_File_read(element, buffer, buffer_size);

	PV_NAPC_FILE_DEBUG("Read %" NAPC_SIZE_PRINTF " bytes from file", ret);

	return ret;
}
