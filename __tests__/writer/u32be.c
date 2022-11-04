#include <napc.h>
#include <napc-testing.h>

TEST_CASE("should write u32be correctly") {
	napc_u8 data[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	napc__Writer ctx;

	napc_Writer_init(&ctx, data, sizeof(data));

	TEST_ASSERT(napc_Writer_writeU32BE(&ctx, NAPC_U32_LITERAL(0xdeadbeef)));
	TEST_ASSERT(napc_Writer_writeU32BE(&ctx, NAPC_U32_LITERAL(0xabcdef12)));
	TEST_ASSERT(!napc_Writer_writeU32BE(&ctx, NAPC_U32_LITERAL(0x0000ff00)));

	TEST_ASSERT(
		memcmp(data, "\xde\xad\xbe\xef\xab\xcd\xef\x12\x0\x0", 10) == 0
	);
}
