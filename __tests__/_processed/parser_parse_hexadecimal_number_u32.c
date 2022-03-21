#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_parser__testCase18(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u32.c] It should work properly ... ");
    napc_mute();
	napc_u32 out = 0;

	TEST_ASSERT(napc_parser_parseHexadecimalNumberU32("1234", &out));
	TEST_ASSERT(out == NAPC_U32_LITERAL(0x1234));
}

void PV_napc_parser__testCase19(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u32.c] It should work without output ... ");
    napc_mute();
	TEST_ASSERT(napc_parser_parseHexadecimalNumberU32("1234", NULL));
}

void PV_napc_parser__testCase20(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u32.c] It should return false given an empty string ... ");
    napc_mute();
	napc_u32 out = 0;

	TEST_ASSERT(!napc_parser_parseHexadecimalNumberU32("", &out));
}

void PV_napc_parser__testCase21(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u32.c] It should return false given a string that contains non-numeric characters ... ");
    napc_mute();
	napc_u32 out = 0;

	TEST_ASSERT(!napc_parser_parseHexadecimalNumberU32("12y34", &out));
}
