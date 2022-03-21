#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_parser__testCase38(void) {
    napc_unmute();
    napc_puts("[parser/parse_decimal_number_u16.c] It should work properly ... ");
    napc_mute();
	napc_u16 out = 0;

	TEST_ASSERT(napc_parser_parseDecimalNumberU16("1234", &out));
	TEST_ASSERT(out == 1234u);
}

void PV_napc_parser__testCase39(void) {
    napc_unmute();
    napc_puts("[parser/parse_decimal_number_u16.c] It should work without output ... ");
    napc_mute();
	TEST_ASSERT(napc_parser_parseDecimalNumberU16("1234", NULL));
}

void PV_napc_parser__testCase40(void) {
    napc_unmute();
    napc_puts("[parser/parse_decimal_number_u16.c] It should return false given an empty string ... ");
    napc_mute();
	napc_u16 out = 0;

	TEST_ASSERT(!napc_parser_parseDecimalNumberU16("", &out));
}

void PV_napc_parser__testCase41(void) {
    napc_unmute();
    napc_puts("[parser/parse_decimal_number_u16.c] It should return false given a string that contains non-numeric characters ... ");
    napc_mute();
	napc_u16 out = 0;

	TEST_ASSERT(!napc_parser_parseDecimalNumberU16("12a34", &out));
}
