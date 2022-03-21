#include <hw.module/file/_private/_file.h>

napc_ssize napc_File_write(napc__File file, const void *data, napc_size data_size) {
	void *element = napc_Pool_getAddress(&PV_napc_fs_handles_pool, file);

	napc_size ret = HAL_napc_File_write(element, data, data_size);

	PV_NAPC_FILE_DEBUG("Wrote %" NAPC_SIZE_PRINTF " bytes to file", ret);

	return ret;
}
