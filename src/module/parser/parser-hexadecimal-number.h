#if !defined(NAPC_MODULE_PARSER_HEXADECIMAL_NUMBER_h)
	#define NAPC_MODULE_PARSER_HEXADECIMAL_NUMBER_h

	#include <libnapc-internal.h>

	/*!
	 * @name napc_parser_parseHexadecimalNumberU8
	 * @brief Parse a decimal number from string.
	 * @version 1.0.0
	 * @description
	 * Parse a string containing a hexadecimal number.
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * libnapc_u8 out;
	 * 
	 * if (napc_parser_parseHexadecimalNumberU8("ef", &out)) {
	 *     napc_printf("Value is %ld", out); // "Value is 239"
	 * }
	 */
	bool napc_parser_parseHexadecimalNumberU8(
		const char *string,
		libnapc_u8 *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_parser_parseHexadecimalNumberU16
	 * @brief Parse a decimal number from string.
	 * @version 1.0.0
	 * @description
	 * Parse a string containing a hexadecimal number.
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * libnapc_u16 out;
	 * 
	 * if (napc_parser_parseHexadecimalNumberU16("beef", &out)) {
	 *     napc_printf("Value is %ld", out); // "Value is 48879"
	 * }
	 */
	bool napc_parser_parseHexadecimalNumberU16(
		const char *string,
		libnapc_u16 *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_parser_parseHexadecimalNumberU32
	 * @brief Parse a decimal number from string.
	 * @version 1.0.0
	 * @description
	 * Parse a string containing a hexadecimal number.
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * libnapc_u32 out;
	 * 
	 * if (napc_parser_parseHexadecimalNumberU32("deadbeef", &out)) {
	 *     napc_printf("Value is %ld", out); // "Value is 3735928559"
	 * }
	 */
	bool napc_parser_parseHexadecimalNumberU32(
		const char *string,
		libnapc_u32 *out
	) NAPC_FN_WARNUNUSED_RET();
#endif
