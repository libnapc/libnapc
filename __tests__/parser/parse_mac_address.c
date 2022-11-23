#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("It should work properly") {
	napc_u8 out[6];

	TEST_ASSERT(napc_parser_parseMACAddress("11:22:33:44:55:66", out));
	TEST_ASSERT(out[0] == 0x11);
	TEST_ASSERT(out[1] == 0x22);
	TEST_ASSERT(out[2] == 0x33);
	TEST_ASSERT(out[3] == 0x44);
	TEST_ASSERT(out[4] == 0x55);
	TEST_ASSERT(out[5] == 0x66);
}

TEST_CASE("It should work without output") {
	TEST_ASSERT(napc_parser_parseMACAddress("11:22:33:44:55:66", NULL));
}

TEST_CASE("It should return false for invalid formatted addresses") {
	// 1 octet missing
	TEST_ASSERT(!napc_parser_parseMACAddress("11:22:33:44:55", NULL));
	// All octets present, but one is too long
	TEST_ASSERT(!napc_parser_parseMACAddress("11:22:33:44:555:66", NULL));
	// Too many octets
	TEST_ASSERT(!napc_parser_parseMACAddress("11:22:33:44:55:66:77", NULL));
	// Invalid format 1
	TEST_ASSERT(!napc_parser_parseMACAddress("11:22:33:44:55:66:", NULL));
	// Invalid characters inside octet
	TEST_ASSERT(!napc_parser_parseMACAddress("11:22:33:4u:55:66", NULL));
}
