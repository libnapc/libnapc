// needs doc-block fixing
#if !defined(LIBNAPC_UTILS_h)
	#define LIBNAPC_UTILS_h

	#include <libnapc-internal.h>

	/*!
	 * The `snprintf()` function defined by the C-Standard does not guarantee that the resulting string is NUL-terminated.
	 * 
	 * This function ensures the resulting string is always NUL-terminated.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_snprintf
	 * @brief Format printf()-like string.
	 * @version 2.0.0
	 * @param buffer The buffer to write the formatted string to.
	 * @param buffer_size The size of the buffer.
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 * @changelog 2.0.0 initial version
	 * @example
	 * char buffer[512];
	 * 
	 * napc_snprintf(buffer, sizeof(buffer), "Hello %s!", "World!");
	 * 
	 * // buffer now contains 'Hello World!'
	 */
	void libnapc_snprintf(
		char *buffer,
		libnapc_size buffer_size,
		const char *fmt,
		...
	) LIBNAPC_FN_PRINTFLIKE(3, 4);

	/*!
	 * Same as `napc_snprintf()` except it takes a `va_args` list instead of variadic arguments.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_vsnprintf
	 * @brief Format printf()-like string.
	 * @version 2.0.0
	 * @param buffer The buffer to write the formatted string to.
	 * @param buffer_size The size of the buffer.
	 * @param fmt printf()-like format string.
	 * @changelog 2.0.0 initial version
	 */
	void libnapc_vsnprintf(
		char *buffer,
		libnapc_size buffer_size,
		const char *fmt,
		va_list args
	);

	/*!
	 * The `strncpy()` function defined by the C-Standard does not guarantee that the resulting string is NUL-terminated.
	 * 
	 * This function ensures the resulting string is always NUL-terminated.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_strncpy
	 * @brief Copy a string to another location.
	 * @version 2.0.0
	 * @param dest Destination memory location.
	 * @param source String to be copied to dest.
	 * @param dest_size Size of destination.
	 * @changelog 2.0.0 initial version
	 */
	void libnapc_strncpy(char *dest, const char *source, libnapc_size dest_size);

	/*!
	 * Count the number of characters in a string.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_strlen
	 * @brief Get length of string.
	 * @version 2.0.0
	 * @note
	 * This is just an alias for `strlen()`.
	 * @param str The string to be measured.
	 * @return Returns the length of the string.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_size str_length = napc_strlen("Hello World!");
	 * 
	 * napc_printf("String's length is %" LIBNAPC_SIZE_PRINT_DEC "\n", str_length);
	 */
	libnapc_size libnapc_strlen(const char *str) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * Perform case sensitive string comparsion.
	 *
	 * @module Core
	 * @type fn
	 * @fullname napc_streql
	 * @brief Compare two strings.
	 * @version 2.0.0
	 * @param str1 First string.
	 * @param str2 Second string.
	 * @return Returns `true` if `str1` and `str2` are equal in contents.
	 * @changelog 2.0.0 initial version
	 * @example
	 * napc_streql("my_string", "my_string"); // returns true
	 * 
	 * napc_streql("my_string", "mY_sTring"); // returns false
	 * 
	 * napc_streql("my_string", "my_second_string"); // returns false
	 */
	bool libnapc_streql(const char *str1, const char *str2) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * Perform case insensitive string comparsion.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_streqli
	 * @brief Compare two strings.
	 * @version 2.0.0
	 * @param str1 First string.
	 * @param str2 Second string.
	 * @return Returns `true` if `str1` and `str2` are equal in contents.
	 * @changelog 2.0.0 initial version
	 * @example
	 * napc_streqli("my_string", "mY_sTring"); // returns true
	 * 
	 * napc_streqli("my_string", "my_second_string"); // returns false
	 */
	bool libnapc_streqli(const char *str1, const char *str2) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * Compare two memory regions.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_memeql
	 * @brief Compare two memory regions of equal size.
	 * @version 2.0.0
	 * @param data1 Pointer to first memory location.
	 * @param data2 Pointer to second memory location.
	 * @param data_size Size of `data1` (resp. `data2`) in bytes.
	 * @return Returns `true` if `data1` and `data2` have the same content.
	 * @note
	 * The two memory regions need to be of the same size.
	 * @changelog 2.0.0 initial version
	 * @example
	 * char data1[3] = {0, 0, 7};
	 * char data2[3] = {0, 0, 7};
	 * 
	 * if (napc_memeql(data1, data2, 3)) {
	 *     napc_printf("data1 and data2 have the same content");
	 * }
	 */
	bool libnapc_memeql(const void *data1, const void *data2, libnapc_size data_size) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * Clear memory section.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname napc_mzero
	 * @brief Zero out memory region.
	 * @version 2.0.0
	 * @param data Buffer to be zero'd out.
	 * @param data_size Size of `data` buffer.
	 * @changelog 2.0.0 initial version
	 * @example
	 * char buffer[512];
	 * 
	 * // clear data buffer
	 * napc_mzero(buffer, sizeof(buffer));
	 */
	void libnapc_mzero(void *data, libnapc_size data_size);
#endif
