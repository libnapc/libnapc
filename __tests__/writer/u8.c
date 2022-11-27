#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should write u8 correctly") {
	libnapc_u8 data[4] = {0, 0, 0, 0xa};
	libnapc__Writer ctx;

	libnapc_Writer_init(&ctx, data, sizeof(data));

	TEST_ASSERT(libnapc_Writer_writeU8(&ctx, 0x1));
	TEST_ASSERT(libnapc_Writer_writeU8(&ctx, 0x2));
	TEST_ASSERT(libnapc_Writer_writeU8(&ctx, 0x3));
	TEST_ASSERT(libnapc_Writer_writeU8(&ctx, 0xff));
	TEST_ASSERT(!libnapc_Writer_writeU8(&ctx, 0xaa));
	TEST_ASSERT(memcmp(data, "\x1\x2\x3\xff", 4) == 0);
}
