#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("It should work properly") {
	libnapc_u8 out[4];

	TEST_ASSERT(napc_parser_parseIPv4Address("123.25.54.3", out));
	TEST_ASSERT(out[0] == 123);
	TEST_ASSERT(out[1] == 25);
	TEST_ASSERT(out[2] == 54);
	TEST_ASSERT(out[3] == 3);
}

TEST_CASE("It should work without output") {
	TEST_ASSERT(napc_parser_parseIPv4Address("123.25.54.3", NULL));
}

TEST_CASE("It should return false for invalid formatted addresses") {
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
