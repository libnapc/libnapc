#include <hw.module/fs/_private/_fs.h>

bool napc_fs_writeFileCString(
	const char *path, const char *string
) {
	return napc_fs_writeFile(path, string, napc_strlen(string));
}
