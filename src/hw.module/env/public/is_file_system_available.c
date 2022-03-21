#include <hw.module/env/_private/_env.h>

extern bool PV_napc_fs_initialized; // @global

bool napc_env_isFileSystemAvailable(void) {
	return PV_napc_fs_initialized;
}
