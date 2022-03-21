#include <hw.module/file/_private/_file.h>

napc__File napc_File_open(const char *path, const char *mode) {
	if (!PV_napc_fs_initialized) {
		NAPC_PANIC(
			"Attempted to open file without the file system being initialized."
		);
	}

	PV_NAPC_FILE_DEBUG("Opening file '%s' (mode=%s)", path, mode);

	if (!napc_streql(mode, "w") && !napc_streql(mode, "r")) {
		NAPC_PANIC("Invalid mode '%s'", mode);
	}

	napc_ssize fd = napc_Pool_claimElement(&PV_napc_fs_handles_pool);

	if (0 > fd) {
		return -1;
	}

	void *element = napc_Pool_getAddress(&PV_napc_fs_handles_pool, fd);

	if (!HAL_napc_File_open(element, path, mode)) {
		PV_NAPC_FILE_ERROR("Failed to open file '%s' (mode=%s)", path, mode);

		napc_Pool_releaseElement(&PV_napc_fs_handles_pool, fd);

		return -1;
	}

	PV_NAPC_FILE_DEBUG("Successfully opened file '%s'", path);

	return fd;
}
