/*!
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
#if !defined(NAPC_MODULE_PARSER_h)
	#define NAPC_MODULE_PARSER_h

	#include <libnapc.h>

	#include <module/parser/parser-decimal-number.h>
	#include <module/parser/parser-hexadecimal-number.h>

	/*!
	 * @name napc_parser_parseBoolean
	 * @brief Parse a boolean from string.
	 * @version 1.0.0
	 * @description
	 * Attempts to parse a boolean from a string.
	 * 
	 * This function recognizes the following formats:
	 *  - `"yes"`, `"true"`, `"1"` for `true`
	 *  - `"no"`, `"false"`, `"0"` for `false`
	 * @param string The string to be parsed.
	 * @param out Pointer to a variable to store the result. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @notes
	 * The casing of the string formats does not matter. (for example `yeS` is recognized as `true`)
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * bool out;
	 * 
	 * if (napc_parser_parseBoolean("yes", &out)) {
	 *     // parsing sucessfull!
	 *     // `out` now has the value `true`
	 * }
	 */
	bool napc_parser_parseBoolean(
		const char *string,
		bool *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_parser_parseHexString
	 * @brief Parse a string containing hexadecimal characters.
	 * @version 1.0.0
	 * @description
	 * Parse a string of hexadecimal characters.
	 * @param string The string to be parsed.
	 * @param n_bytes Number of bytes to be parsed.
	 * @param out Array to store result. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning
	 * The string's length must exactly be double `n_bytes`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * const char *hex_str = "deadbeefabcdefaa123b";
	 * napc_u8 bytes[10];
	 * 
	 * if (napc_parser_parseHexString(hex_str, 10, bytes)) {
	 *     napc_printf("The hex value is: ");
	 * 
	 *     for (int i = 0; i < 10; ++i) {
	 *         napc_printf("%2.2x", bytes[i]);
	 *     }
	 * 
	 *     napc_printf("\n");
	 * }
	 */
	bool napc_parser_parseHexString(
		const char *string,
		napc_size n_bytes,
		napc_u8 *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_parser_parseMACAddress
	 * @brief Parse a MAC-Address.
	 * @version 1.0.0
	 * @description
	 * Parse a MAC-Address (in the format of `aa:bb:cc:dd:ee:ff`) from string.
	 * @param string String to be parsed.
	 * @param out Array to store result. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning
	 * The output array must have at least 6 elements (6 bytes).
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u8 addr[6];
	 * 
	 * if (napc_parser_parseMACAddress("ab:de:ef:11:22:33", addr)) {
	 *     // addr[0] now contains 171 (0xab)
	 *     // addr[1] now contains 222 (0xde)
	 *     // addr[2] now contains 239 (0xef)
	 *     // addr[3] now contains 17  (0x11)
	 *     // addr[4] now contains 34  (0x22)
	 *     // addr[5] now contains 51  (0x33)
	 * } else {
	 *     napc_printf("Failed to parse MAC-Address!\n");
	 * }
	 */
	bool napc_parser_parseMACAddress(
		const char *string,
		napc_u8 *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_parser_parseIPv4Address
	 * @brief Parse an IPv4-Address.
	 * @version 1.0.0
	 * @description
	 * Parse an IPv4-Address (in the format of `a.b.c.d`) from string.
	 * @param string The string to be parsed.
	 * @param out Array to store result. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning
	 * The output array must have at least 4 elements (4 bytes).
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u8 addr[4];
	 * 
	 * if (napc_parser_parseIPv4Address("1.2.3.4", addr)) {
	 *     // addr[0] now contains 1
	 *     // addr[1] now contains 2
	 *     // addr[2] now contains 3
	 *     // addr[3] now contains 4
	 * } else {
	 *     napc_printf("Failed to parse IP-Address!\n");
	 * }
	 */
	bool napc_parser_parseIPv4Address(
		const char *string,
		napc_u8 *out)
	NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_parser_parseKeyValue
	 * @brief Parse a key,value pair.
	 * @version 1.0.0
	 * @description
	 * Parse a string in `key,value` format.
	 * @param string The string to be parsed.
	 * @param key Buffer to place parsed key string.
	 * @param key_len Size of `key` buffer.
	 * @param value Buffer to place parsed value string.
	 * @param value_len Size of `value` buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char key[32];
	 * char value[32];
	 * 
	 * bool result = napc_parser_parseKeyValue(
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
	bool napc_parser_parseKeyValue(
		const char *string,
		char *key, napc_size key_len,
		char *value, napc_size value_len
	) NAPC_FN_WARNUNUSED_RET();
#endif
