#if !defined(PV_NAPC_MODULE_PARSER_h)
	#define PV_NAPC_MODULE_PARSER_h

	#include <module/parser/parser.h>

	#include <napc-utils/napc-utils.h> // napc_strlen(), napc_strncpy(), napc_mzero()
	#include <string.h> // strtok_r()

	napc_size PV_napc_parser_countOccurrences(
		const char *string,
		char ch
	);

	bool PV_napc_parser_parseIntegerString(
		const char *string,
		napc_u32 *out,
		bool isHex
	);
#endif
