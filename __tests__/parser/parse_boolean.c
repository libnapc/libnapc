#include <libnapc.h>
#include <libnapc-testing.h>

/**
 * True values
 */
TEST_CASE("It should work properly (word true)") {
	bool out = false;

	TEST_ASSERT(napc_parser_parseBoolean("true", &out));
	TEST_ASSERT(out);
}

TEST_CASE("It should work properly (word trUe)") {
	bool out = false;

	TEST_ASSERT(napc_parser_parseBoolean("trUe", &out));
	TEST_ASSERT(out);
}

TEST_CASE("It should work properly (word yes)") {
	bool out = false;

	TEST_ASSERT(napc_parser_parseBoolean("yes", &out));
	TEST_ASSERT(out);
}

TEST_CASE("It should work properly (word 1)") {
	bool out = false;

	TEST_ASSERT(napc_parser_parseBoolean("1", &out));
	TEST_ASSERT(out);
}

/**
 * False values
 */
TEST_CASE("It should work properly (word false)") {
	bool out = true;

	TEST_ASSERT(napc_parser_parseBoolean("false", &out));
	TEST_ASSERT(!out);
}

TEST_CASE("It should work properly (word faLse)") {
	bool out = true;

	TEST_ASSERT(napc_parser_parseBoolean("faLse", &out));
	TEST_ASSERT(!out);
}

TEST_CASE("It should work properly (word no)") {
	bool out = true;

	TEST_ASSERT(napc_parser_parseBoolean("no", &out));
	TEST_ASSERT(!out);
}

TEST_CASE("It should work properly (word 0)") {
	bool out = true;

	TEST_ASSERT(napc_parser_parseBoolean("0", &out));
	TEST_ASSERT(!out);
}

TEST_CASE("It should work without output") {
	TEST_ASSERT(napc_parser_parseBoolean("yes", NULL));
	TEST_ASSERT(napc_parser_parseBoolean("no", NULL));
	TEST_ASSERT(napc_parser_parseBoolean("0", NULL));
}

TEST_CASE("It should return false given an empty string") {
	bool out;

	TEST_ASSERT(!napc_parser_parseBoolean("", &out));
}

TEST_CASE("It should return false given an invalid string") {
	bool out;

	TEST_ASSERT(!napc_parser_parseBoolean("trua", &out));
}
