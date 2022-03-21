#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_reader__testCase61(void) {
    napc_unmute();
    napc_puts("[reader/string.c] should read strings correctly ... ");
    napc_mute();
	char data[5] = {'h', 'e', 'l', 'l', 'o'};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	char out[6] = {1,1,1,1,1,1};

	TEST_ASSERT(napc_Reader_readString(&ctx, 2, out, sizeof(out)));
	TEST_ASSERT(memcmp(out, "he\x00", 3) == 0);
	TEST_ASSERT(napc_Reader_readString(&ctx, 2, out, sizeof(out)));
	TEST_ASSERT(memcmp(out, "ll\x00", 3) == 0);
	TEST_ASSERT(napc_Reader_readString(&ctx, 1, out, sizeof(out)));
	TEST_ASSERT(memcmp(out, "o\x00", 2) == 0);
	TEST_ASSERT(!napc_Reader_readString(&ctx, 1, out, sizeof(out)));
}

void PV_napc_reader__testCase62(void) {
    napc_unmute();
    napc_puts("[reader/string.c] should handle overflow (buffer) correctly ... ");
    napc_mute();
	char data[5] = {'h', 'e', 'l', 'l', 'o'};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	char out[7] = {1,1,1,1,1,1,1};
	TEST_ASSERT(!napc_Reader_readString(&ctx, 6, out, sizeof(out)));
}

void PV_napc_reader__testCase63(void) {
    napc_unmute();
    napc_puts("[reader/string.c] should handle overflow (out) correctly ... ");
    napc_mute();
	char data[5] = {'h', 'e', 'l', 'l', 'o'};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	char out[5] = {1,1,1,1,1};
	TEST_ASSERT(!napc_Reader_readString(&ctx, 5, out, sizeof(out)));
}
