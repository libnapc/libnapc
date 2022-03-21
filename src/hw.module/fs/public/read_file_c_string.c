#include <hw.module/fs/_private/_fs.h>

bool napc_fs_readFileCString(
	const char *path, char *buffer, napc_size buffer_size
) {
	if (!buffer_size) {
		NAPC_PANIC(
			"out_size cannot be zero inside napc_fs_readFileCString()."
		);
	}

	napc__Buffer buf;
	napc_Buffer_init(&buf, buffer, buffer_size - 1);

	if (!napc_fs_readFile(path, &buf)) {
		return false;
	}

	// Terminate string
	buffer[buf.size] = 0;
	// Make sure out is always terminated
	buffer[buffer_size - 1] = 0;

	return true;
}
