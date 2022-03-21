#if !defined(NAPC_HW_MODULE_FS_h)
	#define NAPC_HW_MODULE_FS_h

	#include <libnapc.h>

	#include <module/buffer/buffer.h>

	/*!
	 * @name napc_fs_writeFile
	 * @brief Write data to a file.
	 * @version 1.0.0
	 * @description
	 * Writes data to a file overwriting its previous contents.
	 * @param path File path.
	 * @param buffer Buffer to write.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning This function will always overwrite the previous contents of the file.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_fs_writeFile(
		const char *path, const void *buffer, napc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_fs_writeFileCString
	 * @brief Write a string to a file.
	 * @version 1.0.0
	 * @description
	 * Writes a string to a file overwriting its previous contents.
	 * @param path File path.
	 * @param string String to write to file.
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning This function will always overwrite the previous contents of the file.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_fs_writeFileCString(
		const char *path, const char *string
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_fs_readFile
	 * @brief Read a file in its entirety.
	 * @version 1.0.0
	 * @description
	 * Reads the entire content of a file into a buffer.
	 * @param path File path.
	 * @param buffer Buffer to write to.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_fs_readFile(
		const char *path, napc__Buffer *buffer
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_fs_readFileCString
	 * @brief Read a file in its entirety.
	 * @version 1.0.0
	 * @description
	 * Reads the entire content of a file into a NUL-terminated string.
	 * @param path File path.
	 * @param buffer Buffer to write to.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_fs_readFileCString(
		const char *path, char *buffer, napc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();
#endif
