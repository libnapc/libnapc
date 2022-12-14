#if !defined(PV_LIBNAPC_MODULE_PARSER_h)
	#define PV_LIBNAPC_MODULE_PARSER_h

	#include <module/parser/parser.h>

	#include <libnapc-utils/libnapc-utils.h> // libnapc_strlen(), libnapc_strncpy(), libnapc_mzero()
	#include <string.h> // strtok_r()

	libnapc_size PV_libnapc_parser_countOccurrences(
		const char *string,
		char ch
	);

	bool PV_libnapc_parser_parseIntegerString(
		const char *string,
		libnapc_u32 *out,
		bool isHex
	);
#endif
