#if !defined(LIBNAPC_MODULE_PARSER_HEXADECIMAL_NUMBER_h)
	#define LIBNAPC_MODULE_PARSER_HEXADECIMAL_NUMBER_h

	#include <libnapc-internal.h>

	/*!
	 * Parses a string containing a hexadecimal number.
	 * 
	 * @module parser
	 * @type fn
	 * @fullname libnapc_parser_parseHexadecimalNumberU8
	 * @name parseHexadecimalNumberU8
	 * @brief Parse a decimal number from string.
	 * @version 2.0.0
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 out;
	 * 
	 * if (libnapc_parser_parseHexadecimalNumberU8("ef", &out)) {
	 *     libnapc_printf("Value is %ld", out); // "Value is 239"
	 * }
	 */
	bool libnapc_parser_parseHexadecimalNumberU8(
		const char *string,
		libnapc_u8 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Parses a string containing a hexadecimal number.
	 * 
	 * @module parser
	 * @type fn
	 * @fullname libnapc_parser_parseHexadecimalNumberU16
	 * @name parseHexadecimalNumberU16
	 * @brief Parse a decimal number from string.
	 * @version 2.0.0
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u16 out;
	 * 
	 * if (libnapc_parser_parseHexadecimalNumberU16("beef", &out)) {
	 *     libnapc_printf("Value is %ld", out); // "Value is 48879"
	 * }
	 */
	bool libnapc_parser_parseHexadecimalNumberU16(
		const char *string,
		libnapc_u16 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Parses a string containing a hexadecimal number.
	 * 
	 * @module parser
	 * @type fn
	 * @fullname libnapc_parser_parseHexadecimalNumberU32
	 * @name parseHexadecimalNumberU32
	 * @brief Parse a decimal number from string.
	 * @version 2.0.0
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u32 out;
	 * 
	 * if (libnapc_parser_parseHexadecimalNumberU32("deadbeef", &out)) {
	 *     libnapc_printf("Value is %ld", out); // "Value is 3735928559"
	 * }
	 */
	bool libnapc_parser_parseHexadecimalNumberU32(
		const char *string,
		libnapc_u32 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();
#endif
