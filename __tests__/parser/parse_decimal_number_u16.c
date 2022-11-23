#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("It should work properly") {
	libnapc_u16 out = 0;

	TEST_ASSERT(napc_parser_parseDecimalNumberU16("1234", &out));
	TEST_ASSERT(out == 1234u);
}

TEST_CASE("It should work without output") {
	TEST_ASSERT(napc_parser_parseDecimalNumberU16("1234", NULL));
}

TEST_CASE("It should return false given an empty string") {
	libnapc_u16 out = 0;

	TEST_ASSERT(!napc_parser_parseDecimalNumberU16("", &out));
}

TEST_CASE("It should return false given a string that contains non-numeric characters") {
	libnapc_u16 out = 0;

	TEST_ASSERT(!napc_parser_parseDecimalNumberU16("12a34", &out));
}
