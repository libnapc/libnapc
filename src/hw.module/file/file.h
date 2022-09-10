#if !defined(NAPC_HW_MODULE_FILE_h)
	#define NAPC_HW_MODULE_FILE_h

	#include <libnapc.h>

	/*!
	 * @name napc__File
	 * @brief Representation of a file.
	 * @version 1.0.0
	 * @description
	 * Representation of a file.
	 * @opaque
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef napc_ssize napc__File;

	/*!
	 * @name napc_File_open
	 * @brief Open a file.
	 * @version 1.0.0
	 * @description
	 * Open a file for reading or writing.
	 * @param path Path to the file.
	 * @param mode Mode (`"r"` for reading, `"w"` for writing).
	 * @return Returns a negative number if file could not be opened.
	 * @notes
	 * On linux the environment variable `NAPC_FILE_ROOT_PATH` is prepended to `path`.
	 * @warning
	 * Opening a file in write mode (`"w"`) will always clear the previous contents of the file.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc__File fd = napc_File_open("TEST.TXT", "r");
	 * 
	 * if (0 > fd) {
	 *     NAPC_PANIC("Failed to open TEST.TXT!");
	 * }
	 */
	napc__File napc_File_open(const char *path, const char *mode) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_File_write
	 * @brief Write to a file.
	 * @version 1.0.0
	 * @description
	 * Write data to an open file.
	 * @param file File to write to.
	 * @param data Buffer to write.
	 * @param data_size Size of buffer.
	 * @return Returns the number of bytes written or `-1` on error.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_ssize napc_File_write(napc__File file, const void *data, napc_size data_size);

	/*!
	 * @name napc_File_read
	 * @brief Read from a file.
	 * @version 1.0.0
	 * @description
	 * Reads data from an open file.
	 * @param file File to read from.
	 * @param buffer Buffer to write data to.
	 * @param buffer_size Size of buffer.
	 * @return Returns the number of bytes read or `-1` on error.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_ssize napc_File_read(napc__File file, void *buffer, napc_size buffer_size);

	/*!
	 * @name napc_File_getSize
	 * @brief Get size of file.
	 * @version 1.0.0
	 * @description
	 * Get the size of an open file.
	 * @param file File to be measured.
	 * @return Returns the file size in bytes.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_size napc_File_getSize(napc__File file);

	/*!
	 * @name napc_File_close
	 * @brief Close open file.
	 * @version 1.0.0
	 * @description
	 * Close an open file.
	 * @param file File to be closed.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void napc_File_close(napc__File file);
#endif
