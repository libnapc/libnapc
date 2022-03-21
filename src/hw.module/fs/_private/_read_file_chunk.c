#include <hw.module/fs/_private/_fs.h>

napc_ssize PV_nap_fs_readFileChunk(
	const void *data, napc_size data_size, void *context
) {
	napc__File f = (napc__File)context;

	return napc_File_read(f, (void *)data, data_size);
}
