#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_parser__testCase53(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u16.c] It should work properly ... ");
    napc_mute();
	napc_u16 out = 0;

	TEST_ASSERT(napc_parser_parseHexadecimalNumberU16("1234", &out));
	TEST_ASSERT(out == 0x1234u);
}

void PV_napc_parser__testCase54(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u16.c] It should work without output ... ");
    napc_mute();
	TEST_ASSERT(napc_parser_parseHexadecimalNumberU16("1234", NULL));
}

void PV_napc_parser__testCase55(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u16.c] It should return false given an empty string ... ");
    napc_mute();
	napc_u16 out = 0;

	TEST_ASSERT(!napc_parser_parseHexadecimalNumberU16("", &out));
}

void PV_napc_parser__testCase56(void) {
    napc_unmute();
    napc_puts("[parser/parse_hexadecimal_number_u16.c] It should return false given a string that contains non-numeric characters ... ");
    napc_mute();
	napc_u16 out = 0;

	TEST_ASSERT(!napc_parser_parseHexadecimalNumberU16("12y34", &out));
}
