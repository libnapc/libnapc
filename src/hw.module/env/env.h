#if !defined(NAPC_HW_MODULE_ENV_h)
	#define NAPC_HW_MODULE_ENV_h

	#include <libnapc.h>

	/*!
	 * @name napc_env_isFileSystemAvailable
	 * @brief Check file system availability.
	 * @version 1.1.0
	 * @return Returns `true` if file system functionality is available.
	 * @changelog 1.1.0 18.03.2022 initial version
	 * @example
	 * if (napc_env_isFileSystemAvailable()) {
	 *     napc_printf("File System is available.\n");
	 * }
	 */
	bool napc_env_isFileSystemAvailable(void) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_env_isEthernetAvailable
	 * @brief Check ethernet availability.
	 * @version 1.1.0
	 * @return Returns `true` if ethernet functionality is available.
	 * @changelog 1.1.0 18.03.2022 initial version
	 * @example
	 * if (napc_env_isEthernetAvailable()) {
	 *     napc_printf("Ethernet is available.\n");
	 * }
	 */
	bool napc_env_isEthernetAvailable(void) NAPC_FN_WARNUNUSED_RET();
#endif
