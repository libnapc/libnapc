#if !defined(LIBNAPC_MODULE_PARSER_DECIMAL_NUMBER_h)
	#define LIBNAPC_MODULE_PARSER_DECIMAL_NUMBER_h

	#include <libnapc-internal.h>

	/*!
	 * @name napc_parser_parseDecimalNumberU8
	 * @brief Parse a hexadecimal number from string.
	 * @version 1.0.0
	 * @description
	 * Parse a string containing a decimal number.
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * libnapc_u8 out;
	 * 
	 * if (napc_parser_parseDecimalNumberU8("123", &out)) {
	 *     napc_printf("Value is %d", out); // "Value is 123"
	 * }
	 */
	bool libnapc_parser_parseDecimalNumberU8(
		const char *string, libnapc_u8 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * @name napc_parser_parseDecimalNumberU16
	 * @brief Parse a hexadecimal number from string.
	 * @version 1.0.0
	 * @description
	 * Parse a string containing a decimal number.
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * libnapc_u16 out;
	 * 
	 * if (napc_parser_parseDecimalNumberU16("1024", &out)) {
	 *     napc_printf("Value is %d", out); // "Value is 1024"
	 * }
	 */
	bool libnapc_parser_parseDecimalNumberU16(
		const char *string, libnapc_u16 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * @name napc_parser_parseDecimalNumberU32
	 * @brief Parse a hexadecimal number from string.
	 * @version 1.0.0
	 * @description
	 * Parse a string containing a decimal number.
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * libnapc_u32 out;
	 * 
	 * if (napc_parser_parseDecimalNumberU32("123456", &out)) {
	 *     napc_printf("Value is %ld", out); // "Value is 123456"
	 * }
	 */
	bool libnapc_parser_parseDecimalNumberU32(
		const char *string, libnapc_u32 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();
#endif
