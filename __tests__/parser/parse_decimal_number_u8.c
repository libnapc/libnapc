#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("It should work properly") {
	libnapc_u8 out = 0;

	TEST_ASSERT(libnapc_parser_parseDecimalNumberU8("1234", &out));
	TEST_ASSERT(out == 210);
}

TEST_CASE("It should work without output") {
	TEST_ASSERT(libnapc_parser_parseDecimalNumberU8("1234", NULL));
}

TEST_CASE("It should return false given an empty string") {
	libnapc_u8 out = 0;

	TEST_ASSERT(!libnapc_parser_parseDecimalNumberU8("", &out));
}

TEST_CASE("It should return false given a string that contains non-numeric characters") {
	libnapc_u8 out = 0;

	TEST_ASSERT(!libnapc_parser_parseDecimalNumberU8("12a34", &out));
}
