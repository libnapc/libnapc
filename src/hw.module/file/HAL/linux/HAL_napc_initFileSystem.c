#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>
	#include <napc-serial/napc-serial.h> // napc_printf()
	#include <napc-utils/napc-utils.h> // napc_strncpy()

	#include <stdlib.h> // getenv(), realpath()
	#include <limits.h> // PATH_MAX

	char PV_napc_fs_linuxRootPath[512]; // @global

	static void setRootPath(const char *path) {
		napc_printf("HAL_napc_initFileSystem (linux) root path = '%s'\n", path);

		napc_strncpy(
			PV_napc_fs_linuxRootPath,
			path,
			sizeof(PV_napc_fs_linuxRootPath)
		);
	}

	void HAL_napc_initFileSystem(void) {
		napc_mzero(PV_napc_fs_linuxRootPath, sizeof(PV_napc_fs_linuxRootPath));

		const char *root_path = getenv("NAPC_FILE_ROOT_PATH");

		if (!root_path) {
			root_path = ".";
		}

		// only resolve NAPC_FILE_ROOT_PATH if this environment variable
		// was not set
		if (!getenv("NAPC_FILE_NO_RESOLVE_ROOT_PATH")) {
			char resolved_root_path[PATH_MAX];

			if (realpath(root_path, resolved_root_path)) {
				setRootPath(resolved_root_path);
			} else {
				napc_printf("!!! ERROR failed to resolve '%s' !!!\n", root_path);

				setRootPath("");
			}
		} else {
			setRootPath(root_path);
		}

		PV_napc_fs_initialized = true;
	}
#endif
