#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should read u8 array correctly") {
	char data[5] = {'h', 'e', 'l', 'l', 'o'};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	libnapc_u8 out[6] = {1,1,1,1,1,1};

	TEST_ASSERT(napc_Reader_readU8Array(&ctx, 2, out));
	TEST_ASSERT(memcmp(out, "he\x1\x1\x1\x1", 6) == 0);
	TEST_ASSERT(napc_Reader_readU8Array(&ctx, 2, out));
	TEST_ASSERT(memcmp(out, "ll\x1\x1\x1\x1", 6) == 0);
	TEST_ASSERT(napc_Reader_readU8Array(&ctx, 1, out));
	TEST_ASSERT(memcmp(out, "o", 1) == 0);
	TEST_ASSERT(!napc_Reader_readU8Array(&ctx, 1, out));
}

TEST_CASE("should handle overflow (buffer) correctly") {
	char data[5] = {'h', 'e', 'l', 'l', 'o'};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	libnapc_u8 out[7] = {1,1,1,1,1,1,1};
	TEST_ASSERT(!napc_Reader_readU8Array(&ctx, 6, out));
}
