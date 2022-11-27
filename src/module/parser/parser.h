/* <-- add '!' back once ported -->
 * @module parser
 * @name parser:intro
 * @brief String parsing
 * @description
 * This module contains all functions that parse strings.
 * 
 * All functions in this module follow the same rules<sup>*</sup>:
 * 
 * - The first parameter is always the string to be parsed.
 * - Every function returns a boolean indicating success or failure.
 * - It is allowed to pass `NULL` as output. This is useful for checking the format of a string:
 * 
 * ```c
 * if (napc_parser_parseIPv4Address(ip_str, NULL)) {
 * 	// ip_str is a valid IPv4Address
 * }
 * ```
 * 
 * > If a function returned `false` the contents of the parsed output is _undefined_.
 */
#if !defined(LIBNAPC_MODULE_PARSER_h)
	#define LIBNAPC_MODULE_PARSER_h

	#include <libnapc-internal.h>

	#include <module/parser/parser-decimal-number.h>
	#include <module/parser/parser-hexadecimal-number.h>

	/*!
	 * Attempts to parse a boolean from a string.
	 * 
	 * This function recognizes the following formats:
	 *  - `"yes"`, `"true"`, `"1"` for `true`
	 *  - `"no"`, `"false"`, `"0"` for `false`
	 * 
	 * @module parser
	 * @type fn
	 * @fullname libnapc_parser_parseBoolean
	 * @name parseBoolean
	 * @brief Parse a boolean from string.
	 * @version 2.0.0
	 * @param string The string to be parsed.
	 * @param out Pointer to a variable to store the result. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @note
	 * The casing of the string formats does not matter. (for example `yeS` is recognized as `true`)
	 * @changelog 2.0.0 initial version
	 * @example
	 * bool out;
	 * 
	 * if (libnapc_parser_parseBoolean("yes", &out)) {
	 *     // parsing sucessfull!
	 *     // `out` now has the value `true`
	 * }
	 */
	bool libnapc_parser_parseBoolean(
		const char *string,
		bool *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Parses a string of hexadecimal characters.
	 * 
	 * @module parser
	 * @type fn
	 * @fullname libnapc_parser_parseHexString
	 * @name parseHexString
	 * @brief Parse a string containing hexadecimal characters.
	 * @version 2.0.0
	 * @param string The string to be parsed.
	 * @param n_bytes Number of bytes to be parsed.
	 * @param out Array to store result. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning
	 * The string's length must exactly be double `n_bytes`.
	 * @changelog 2.0.0 initial version
	 * @example
	 * const char *hex_str = "deadbeefabcdefaa123b";
	 * libnapc_u8 bytes[10];
	 * 
	 * if (libnapc_parser_parseHexString(hex_str, 10, bytes)) {
	 *     libnapc_printf("The hex value is: ");
	 * 
	 *     for (int i = 0; i < 10; ++i) {
	 *         libnapc_printf("%2.2x", bytes[i]);
	 *     }
	 * 
	 *     libnapc_printf("\n");
	 * }
	 */
	bool libnapc_parser_parseHexString(
		const char *string,
		libnapc_size n_bytes,
		libnapc_u8 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Parses a MAC-Address (in the format of `aa:bb:cc:dd:ee:ff`) from string.
	 * 
	 * @module parser
	 * @type fn
	 * @fullname libnapc_parser_parseMACAddress
	 * @name parseMACAddress
	 * @brief Parse a MAC-Address.
	 * @version 2.0.0
	 * @param string String to be parsed.
	 * @param out Array to store result. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning
	 * The output array must have at least 6 elements (6 bytes).
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 addr[6];
	 * 
	 * if (libnapc_parser_parseMACAddress("ab:de:ef:11:22:33", addr)) {
	 *     // addr[0] now contains 171 (0xab)
	 *     // addr[1] now contains 222 (0xde)
	 *     // addr[2] now contains 239 (0xef)
	 *     // addr[3] now contains 17  (0x11)
	 *     // addr[4] now contains 34  (0x22)
	 *     // addr[5] now contains 51  (0x33)
	 * } else {
	 *     libnapc_printf("Failed to parse MAC-Address!\n");
	 * }
	 */
	bool libnapc_parser_parseMACAddress(
		const char *string,
		libnapc_u8 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Parses an IPv4-Address (in the format of `a.b.c.d`) from string.
	 * 
	 * @module parser
	 * @type fn
	 * @fullname libnapc_parser_parseIPv4Address
	 * @name parseIPv4Address
	 * @brief Parse an IPv4-Address.
	 * @version 2.0.0
	 * @param string The string to be parsed.
	 * @param out Array to store result. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning
	 * The output array must have at least 4 elements (4 bytes).
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 addr[4];
	 * 
	 * if (libnapc_parser_parseIPv4Address("1.2.3.4", addr)) {
	 *     // addr[0] now contains 1
	 *     // addr[1] now contains 2
	 *     // addr[2] now contains 3
	 *     // addr[3] now contains 4
	 * } else {
	 *     libnapc_printf("Failed to parse IP-Address!\n");
	 * }
	 */
	bool libnapc_parser_parseIPv4Address(
		const char *string,
		libnapc_u8 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Parses a string in `key,value` format.
	 * 
	 * @module parser
	 * @type fn
	 * @fullname libnapc_parser_parseKeyValue
	 * @name parseKeyValue
	 * @brief Parse a key,value pair.
	 * @version 2.0.0
	 * @param string The string to be parsed.
	 * @param key Buffer to place parsed key string.
	 * @param key_len Size of `key` buffer.
	 * @param value Buffer to place parsed value string.
	 * @param value_len Size of `value` buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 * @example
	 * char key[32];
	 * char value[32];
	 * 
	 * bool result = libnapc_parser_parseKeyValue(
	 *     "test,1234",
	 *      key, sizeof(key),
	 *      value, sizeof(value)
	 * );
	 * 
	 * if (result) {
	 *     // key is "test"
	 *     // value is "1234"
	 * }
	 */
	bool libnapc_parser_parseKeyValue(
		const char *string,
		char *key, libnapc_size key_len,
		char *value, libnapc_size value_len
	) LIBNAPC_FN_WARN_UNUSED_RET();
#endif
