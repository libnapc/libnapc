#include <hw.module/fs/_private/_fs.h>

bool napc_fs_writeFile(
	const char *path, const void *buffer, napc_size buffer_size
) {
	PV_NAPC_FS_DEBUG("Writing file '%s'.", path);

	napc__File file = napc_File_open(path, "w");

	if (0 > file) return false;

	bool result = napc_misc_chunkedOperation(
		buffer, buffer_size,
		512,
		PV_nap_fs_writeFileChunk, (void *)file
	);

	napc_File_close(file);

	return result;
}
