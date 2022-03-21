#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_parser__testCase57(void) {
    napc_unmute();
    napc_puts("[parser/parse_ipv4_address.c] It should work properly ... ");
    napc_mute();
	napc_u8 out[4];

	TEST_ASSERT(napc_parser_parseIPv4Address("123.25.54.3", out));
	TEST_ASSERT(out[0] == 123);
	TEST_ASSERT(out[1] == 25);
	TEST_ASSERT(out[2] == 54);
	TEST_ASSERT(out[3] == 3);
}

void PV_napc_parser__testCase58(void) {
    napc_unmute();
    napc_puts("[parser/parse_ipv4_address.c] It should work without output ... ");
    napc_mute();
	TEST_ASSERT(napc_parser_parseIPv4Address("123.25.54.3", NULL));
}

void PV_napc_parser__testCase59(void) {
    napc_unmute();
    napc_puts("[parser/parse_ipv4_address.c] It should return false for invalid formatted addresses ... ");
    napc_mute();
	// 1 octet missing
	TEST_ASSERT(!napc_parser_parseIPv4Address("1.2.3", NULL));
	// All octets present, but one is too long
	TEST_ASSERT(!napc_parser_parseIPv4Address("1.4232.2.3", NULL));
	// All octets present, but one is too high
	TEST_ASSERT(!napc_parser_parseIPv4Address("1.432.2.3", NULL));
	// Too many octets
	TEST_ASSERT(!napc_parser_parseIPv4Address("1.2.3.4.5", NULL));
	// Invalid format 1
	TEST_ASSERT(!napc_parser_parseIPv4Address("1.2.3.4.5.", NULL));
	// Invalid characters inside octet
	TEST_ASSERT(!napc_parser_parseIPv4Address("1.2.3a.4", NULL));
}
