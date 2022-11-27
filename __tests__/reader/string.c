#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should read strings correctly") {
	char data[5] = {'h', 'e', 'l', 'l', 'o'};
	napc__Reader ctx;

	libnapc_Reader_init(&ctx, data, sizeof(data));

	char out[6] = {1,1,1,1,1,1};

	TEST_ASSERT(libnapc_Reader_readString(&ctx, 2, out, sizeof(out)));
	TEST_ASSERT(memcmp(out, "he\x00", 3) == 0);
	TEST_ASSERT(libnapc_Reader_readString(&ctx, 2, out, sizeof(out)));
	TEST_ASSERT(memcmp(out, "ll\x00", 3) == 0);
	TEST_ASSERT(libnapc_Reader_readString(&ctx, 1, out, sizeof(out)));
	TEST_ASSERT(memcmp(out, "o\x00", 2) == 0);
	TEST_ASSERT(!libnapc_Reader_readString(&ctx, 1, out, sizeof(out)));
}

TEST_CASE("should handle overflow (buffer) correctly") {
	char data[5] = {'h', 'e', 'l', 'l', 'o'};
	napc__Reader ctx;

	libnapc_Reader_init(&ctx, data, sizeof(data));

	char out[7] = {1,1,1,1,1,1,1};
	TEST_ASSERT(!libnapc_Reader_readString(&ctx, 6, out, sizeof(out)));
}

TEST_CASE("should handle overflow (out) correctly") {
	char data[5] = {'h', 'e', 'l', 'l', 'o'};
	napc__Reader ctx;

	libnapc_Reader_init(&ctx, data, sizeof(data));

	char out[5] = {1,1,1,1,1};
	TEST_ASSERT(!libnapc_Reader_readString(&ctx, 5, out, sizeof(out)));
}
