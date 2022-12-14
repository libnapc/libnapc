#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should write u16be correctly") {
	libnapc_u8 data[5] = {0, 0, 0, 0, 0};
	libnapc__Writer ctx;

	libnapc_Writer_init(&ctx, data, sizeof(data));

	TEST_ASSERT(libnapc_Writer_writeU16BE(&ctx, LIBNAPC_U16_LITERAL(0xabde)));
	TEST_ASSERT(libnapc_Writer_writeU16BE(&ctx, LIBNAPC_U16_LITERAL(0xcdef)));
	TEST_ASSERT(!libnapc_Writer_writeU16BE(&ctx, LIBNAPC_U16_LITERAL(0xff00)));

	TEST_ASSERT(memcmp(data, "\xab\xde\xcd\xef", 5) == 0);
}
