#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("It should work properly") {
	napc_u32 out = 0;

	TEST_ASSERT(napc_parser_parseHexadecimalNumberU32("1234", &out));
	TEST_ASSERT(out == NAPC_U32_LITERAL(0x1234));
}

TEST_CASE("It should work without output") {
	TEST_ASSERT(napc_parser_parseHexadecimalNumberU32("1234", NULL));
}

TEST_CASE("It should return false given an empty string") {
	napc_u32 out = 0;

	TEST_ASSERT(!napc_parser_parseHexadecimalNumberU32("", &out));
}

TEST_CASE("It should return false given a string that contains non-numeric characters") {
	napc_u32 out = 0;

	TEST_ASSERT(!napc_parser_parseHexadecimalNumberU32("12y34", &out));
}
