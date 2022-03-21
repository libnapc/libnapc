#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_reader__testCase68(void) {
    napc_unmute();
    napc_puts("[reader/u8_array.c] should read u8 array correctly ... ");
    napc_mute();
	char data[5] = {'h', 'e', 'l', 'l', 'o'};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	napc_u8 out[6] = {1,1,1,1,1,1};

	TEST_ASSERT(napc_Reader_readU8Array(&ctx, 2, out));
	TEST_ASSERT(memcmp(out, "he\x1\x1\x1\x1", 6) == 0);
	TEST_ASSERT(napc_Reader_readU8Array(&ctx, 2, out));
	TEST_ASSERT(memcmp(out, "ll\x1\x1\x1\x1", 6) == 0);
	TEST_ASSERT(napc_Reader_readU8Array(&ctx, 1, out));
	TEST_ASSERT(memcmp(out, "o", 1) == 0);
	TEST_ASSERT(!napc_Reader_readU8Array(&ctx, 1, out));
}

void PV_napc_reader__testCase69(void) {
    napc_unmute();
    napc_puts("[reader/u8_array.c] should handle overflow (buffer) correctly ... ");
    napc_mute();
	char data[5] = {'h', 'e', 'l', 'l', 'o'};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	napc_u8 out[7] = {1,1,1,1,1,1,1};
	TEST_ASSERT(!napc_Reader_readU8Array(&ctx, 6, out));
}
