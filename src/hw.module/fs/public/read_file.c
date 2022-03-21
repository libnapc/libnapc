#include <hw.module/fs/_private/_fs.h>

bool napc_fs_readFile(
	const char *path, napc__Buffer *buffer
) {
	NAPC_MAGIC_ASSERT(napc__Buffer, buffer);

	PV_NAPC_FS_DEBUG("Reading file '%s'.", path);

	napc__File file = napc_File_open(path, "r");

	if (0 > file) return false;

	napc_size size_to_read = napc_File_getSize(file);

	if (size_to_read > buffer->size) {
		napc_File_close(file);

		PV_NAPC_FS_ERROR(
			"Cannot possibly fit file into buffer (buffer's too small)."
			"Buffer size: %" NAPC_SIZE_PRINTF " File size: %" NAPC_SIZE_PRINTF,
			buffer->size, size_to_read
		);

		return false;
	}

	bool result = napc_misc_chunkedOperation(
		buffer->data, size_to_read, 512, PV_nap_fs_readFileChunk, (void *)file
	);

	buffer->size = size_to_read;

	napc_File_close(file);

	return result;
}
