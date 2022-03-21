#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_parser__testCase26(void) {
    napc_unmute();
    napc_puts("[parser/parse_decimal_number_u8.c] It should work properly ... ");
    napc_mute();
	napc_u8 out = 0;

	TEST_ASSERT(napc_parser_parseDecimalNumberU8("1234", &out));
	TEST_ASSERT(out == 210);
}

void PV_napc_parser__testCase27(void) {
    napc_unmute();
    napc_puts("[parser/parse_decimal_number_u8.c] It should work without output ... ");
    napc_mute();
	TEST_ASSERT(napc_parser_parseDecimalNumberU8("1234", NULL));
}

void PV_napc_parser__testCase28(void) {
    napc_unmute();
    napc_puts("[parser/parse_decimal_number_u8.c] It should return false given an empty string ... ");
    napc_mute();
	napc_u8 out = 0;

	TEST_ASSERT(!napc_parser_parseDecimalNumberU8("", &out));
}

void PV_napc_parser__testCase29(void) {
    napc_unmute();
    napc_puts("[parser/parse_decimal_number_u8.c] It should return false given a string that contains non-numeric characters ... ");
    napc_mute();
	napc_u8 out = 0;

	TEST_ASSERT(!napc_parser_parseDecimalNumberU8("12a34", &out));
}
