#if !defined(LIBNAPC_MODULE_PARSER_DECIMAL_NUMBER_h)
	#define LIBNAPC_MODULE_PARSER_DECIMAL_NUMBER_h

	#include <libnapc-internal.h>

	/*!
	 * Parses a string containing a decimal number.
	 * 
	 * @module parser
	 * @type fn
	 * @fullname libnapc_parser_parseDecimalNumberU8
	 * @name parseDecimalNumberU8
	 * @brief Parse a hexadecimal number from string.
	 * @version 2.0.0
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 out;
	 * 
	 * if (libnapc_parser_parseDecimalNumberU8("123", &out)) {
	 *     libnapc_printf("Value is %d", out); // "Value is 123"
	 * }
	 */
	bool libnapc_parser_parseDecimalNumberU8(
		const char *string, libnapc_u8 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Parses a string containing a decimal number.
	 * 
	 * @module parser
	 * @type fn
	 * @fullname libnapc_parser_parseDecimalNumberU16
	 * @name parseDecimalNumberU16
	 * @brief Parse a hexadecimal number from string.
	 * @version 2.0.0
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u16 out;
	 * 
	 * if (libnapc_parser_parseDecimalNumberU16("1024", &out)) {
	 *     libnapc_printf("Value is %d", out); // "Value is 1024"
	 * }
	 */
	bool libnapc_parser_parseDecimalNumberU16(
		const char *string, libnapc_u16 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Parses a string containing a decimal number.
	 * 
	 * @module parser
	 * @type fn
	 * @fullname libnapc_parser_parseDecimalNumberU32
	 * @name parseDecimalNumberU32
	 * @brief Parse a hexadecimal number from string.
	 * @version 2.0.0
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u32 out;
	 * 
	 * if (libnapc_parser_parseDecimalNumberU32("123456", &out)) {
	 *     libnapc_printf("Value is %ld", out); // "Value is 123456"
	 * }
	 */
	bool libnapc_parser_parseDecimalNumberU32(
		const char *string, libnapc_u32 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();
#endif
