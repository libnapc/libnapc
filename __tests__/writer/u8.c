#include <napc.h>
#include <napc-testing.h>

TEST_CASE("should write u8 correctly") {
	napc_u8 data[4] = {0, 0, 0, 0xa};
	napc__Writer ctx;

	napc_Writer_init(&ctx, data, sizeof(data), NAPC_WRITER_MODE_REGULAR);

	TEST_ASSERT(napc_Writer_writeU8(&ctx, 0x1));
	TEST_ASSERT(napc_Writer_writeU8(&ctx, 0x2));
	TEST_ASSERT(napc_Writer_writeU8(&ctx, 0x3));
	TEST_ASSERT(napc_Writer_writeU8(&ctx, 0xff));
	TEST_ASSERT(!napc_Writer_writeU8(&ctx, 0xaa));
	TEST_ASSERT(memcmp(data, "\x1\x2\x3\xff", 4) == 0);
}
