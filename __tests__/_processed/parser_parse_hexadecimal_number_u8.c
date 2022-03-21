#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_parser__testCase34(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u8.c] It should work properly ... ");
    napc_mute();
	napc_u8 out = 0;

	TEST_ASSERT(napc_parser_parseHexadecimalNumberU8("1234", &out));
	TEST_ASSERT(out == 52);
}

void PV_napc_parser__testCase35(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u8.c] It should work without output ... ");
    napc_mute();
	TEST_ASSERT(napc_parser_parseHexadecimalNumberU8("1234", NULL));
}

void PV_napc_parser__testCase36(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u8.c] It should return false given an empty string ... ");
    napc_mute();
	napc_u8 out = 0;

	TEST_ASSERT(!napc_parser_parseHexadecimalNumberU8("", &out));
}

void PV_napc_parser__testCase37(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u8.c] It should return false given a string that contains non-numeric characters ... ");
    napc_mute();
	napc_u8 out = 0;

	TEST_ASSERT(!napc_parser_parseHexadecimalNumberU8("12y34", &out));
}
