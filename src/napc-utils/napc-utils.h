#if !defined(NAPC_UTILS_h)
	#define NAPC_UTILS_h

	#include <libnapc-internal.h>

	/*!
	 * @name napc_snprintf
	 * @brief Format printf()-like string.
	 * @version 1.0.0
	 * @rationale
	 * The `snprintf()` function defined by the C-Standard does not guarantee that the resulting string is NUL-terminated.
	 * 
	 * This function ensures the resulting string is always NUL-terminated.
	 * @param buffer The buffer to write the formatted string to.
	 * @param buffer_size The size of the buffer.
	 * @param fmt printf()-like format string.
	 * @param ... Values to incorporate into string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char buffer[512];
	 * 
	 * napc_snprintf(buffer, sizeof(buffer), "Hello %s!", "World!");
	 * 
	 * // buffer now contains 'Hello World!'
	 */
	void libnapc_snprintf(
		char *buffer,
		napc_size buffer_size,
		const char *fmt,
		...
	) NAPC_FN_PRINTFLIKE(3, 4);

	/*!
	 * @name napc_vsnprintf
	 * @brief Format printf()-like string.
	 * @version 1.0.0
	 * @description
	 * Same as `napc_snprintf()` except it takes a `va_args` list instead of variadic arguments.
	 * @param buffer The buffer to write the formatted string to.
	 * @param buffer_size The size of the buffer.
	 * @param fmt printf()-like format string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void libnapc_vsnprintf(
		char *buffer,
		napc_size buffer_size,
		const char *fmt,
		va_list args
	);

	/*!
	 * @name napc_strncpy
	 * @brief Copy a string.
	 * @version 1.0.0
	 * @description
	 * Copy a string to another location.
	 * @rationale
	 * The `strncpy()` function defined by the C-Standard does not guarantee that the resulting string is NUL-terminated.
	 * 
	 * This function ensures the resulting string is always NUL-terminated.
	 * @param dest Destination memory location.
	 * @param source String to be copied to dest.
	 * @param dest_size Size of destination.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void libnapc_strncpy(char *dest, const char *source, napc_size dest_size);

	/*!
	 * @name napc_strlen
	 * @brief Get length of string.
	 * @version 1.0.0
	 * @description
	 * Count the number of characters in a string.
	 * @notes
	 * This is just an alias for `strlen()`.
	 * @param str The string to be measured.
	 * @return Returns the length of the string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_size str_length = napc_strlen("Hello World!");
	 * 
	 * napc_printf("String's length is %" NAPC_SIZE_PRINTF "\n", str_length);
	 */
	napc_size libnapc_strlen(const char *str) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_streql
	 * @brief Compare two strings.
	 * @version 1.0.0
	 * @description
	 * Perform case sensitive string comparsion.
	 * @rationale
	 * It's cumbersome to write `strcmp(str1, str2) == 0` to compare strings.
	 * @param str1 First string.
	 * @param str2 Second string.
	 * @return Returns `true` if `str1` and `str2` are equal in contents.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_streql("my_string", "my_string"); // returns true
	 * 
	 * napc_streql("my_string", "mY_sTring"); // returns false
	 * 
	 * napc_streql("my_string", "my_second_string"); // returns false
	 */
	bool libnapc_streql(const char *str1, const char *str2) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_streqli
	 * @brief Compare two strings.
	 * @version 1.0.0
	 * @description
	 * Perform case insensitive string comparsion.
	 * @rationale
	 * It's cumbersome to write `strcasecmp(str1, str2) == 0` to compare strings.
	 * @param str1 First string.
	 * @param str2 Second string.
	 * @return Returns `true` if `str1` and `str2` are equal in contents.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_streqli("my_string", "mY_sTring"); // returns true
	 * 
	 * napc_streqli("my_string", "my_second_string"); // returns false
	 */
	bool libnapc_streqli(const char *str1, const char *str2) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_memeql
	 * @brief Compare two memory regions of equal size.
	 * @version 1.0.0
	 * @description
	 * Compare two memory regions.
	 * @param data1 Pointer to first memory location.
	 * @param data2 Pointer to second memory location.
	 * @param data_size Size of `data1` (resp. `data2`) in bytes.
	 * @return Returns `true` if `data1` and `data2` have the same content.
	 * @notes
	 * The two memory regions need to be of the same size.
	 * @rationale
	 * It's cumbersome to write `memcmp(data1, data2, data_size) == 0` to compare memory blocks.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char data1[3] = {0, 0, 7};
	 * char data2[3] = {0, 0, 7};
	 * 
	 * if (napc_memeql(data1, data2, 3)) {
	 *     napc_printf("data1 and data2 have the same content");
	 * }
	 */
	bool libnapc_memeql(const void *data1, const void *data2, napc_size data_size) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_mzero
	 * @brief Zero out memory region.
	 * @version 1.0.0
	 * @description
	 * Clear memory section.
	 * @param data Buffer to be zero'd out.
	 * @param data_size Size of `data` buffer.
	 * @rationale
	 * It's cumbersome to write `memset(data, 0, data_size)`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char buffer[512];
	 * 
	 * // clear data buffer
	 * napc_mzero(buffer, sizeof(buffer));
	 */
	void napc_mzero(void *data, napc_size data_size);
#endif
