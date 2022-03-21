#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_parser__testCase13(void) {
    napc_unmute();
    napc_puts("[parser/parse_key_value.c] It should work properly ... ");
    napc_mute();
	char key[32]; char value[32];

	TEST_ASSERT(napc_parser_parseKeyValue("abc,def", key, 32, value, 32));
	TEST_ASSERT(strcmp(key, "abc") == 0);
	TEST_ASSERT(strcmp(value, "def") == 0);
}

void PV_napc_parser__testCase14(void) {
    napc_unmute();
    napc_puts("[parser/parse_key_value.c] It should truncate values properly ... ");
    napc_mute();
	char key[4]; char value[4];

	TEST_ASSERT(napc_parser_parseKeyValue("hello,world", key, 4, value, 4));
	TEST_ASSERT(strcmp(key, "hel") == 0);
	TEST_ASSERT(strcmp(value, "wor") == 0);
}

void PV_napc_parser__testCase15(void) {
    napc_unmute();
    napc_puts("[parser/parse_key_value.c] It should work without output ... ");
    napc_mute();
	TEST_ASSERT(napc_parser_parseKeyValue("abc,def", NULL, 0, NULL, 0));
}

void PV_napc_parser__testCase16(void) {
    napc_unmute();
    napc_puts("[parser/parse_key_value.c] It should work with multiple commas ... ");
    napc_mute();
	char key[32]; char value[32];

	TEST_ASSERT(napc_parser_parseKeyValue("abc,def,123", key, 32, value, 32));
	TEST_ASSERT(strcmp(key, "abc") == 0);
	TEST_ASSERT(strcmp(value, "def,123") == 0);
}

void PV_napc_parser__testCase17(void) {
    napc_unmute();
    napc_puts("[parser/parse_key_value.c] It should return false for invalid formatted strings ... ");
    napc_mute();
	// empty string
	TEST_ASSERT(!napc_parser_parseKeyValue("", NULL, 0, NULL, 0));
	// no comma separator
	TEST_ASSERT(!napc_parser_parseKeyValue("abc", NULL, 0, NULL, 0));
}
