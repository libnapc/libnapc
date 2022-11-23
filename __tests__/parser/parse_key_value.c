#include <napc.h>
#include <libnapc-testing.h>

TEST_CASE("It should work properly") {
	char key[32]; char value[32];

	TEST_ASSERT(napc_parser_parseKeyValue("abc,def", key, 32, value, 32));
	TEST_ASSERT(strcmp(key, "abc") == 0);
	TEST_ASSERT(strcmp(value, "def") == 0);
}

TEST_CASE("It should truncate values properly") {
	char key[4]; char value[4];

	TEST_ASSERT(napc_parser_parseKeyValue("hello,world", key, 4, value, 4));
	TEST_ASSERT(strcmp(key, "hel") == 0);
	TEST_ASSERT(strcmp(value, "wor") == 0);
}

TEST_CASE("It should work without output") {
	TEST_ASSERT(napc_parser_parseKeyValue("abc,def", NULL, 0, NULL, 0));
}

TEST_CASE("It should work with multiple commas") {
	char key[32]; char value[32];

	TEST_ASSERT(napc_parser_parseKeyValue("abc,def,123", key, 32, value, 32));
	TEST_ASSERT(strcmp(key, "abc") == 0);
	TEST_ASSERT(strcmp(value, "def,123") == 0);
}

TEST_CASE("It should return false for invalid formatted strings") {
	// empty string
	TEST_ASSERT(!napc_parser_parseKeyValue("", NULL, 0, NULL, 0));
	// no comma separator
	TEST_ASSERT(!napc_parser_parseKeyValue("abc", NULL, 0, NULL, 0));
}
