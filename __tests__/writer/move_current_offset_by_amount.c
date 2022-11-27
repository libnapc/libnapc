#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work correctly") {
	libnapc_u8 buffer[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

	napc__Writer ctx;
	libnapc_Writer_init(&ctx, buffer, sizeof(buffer));

	// shoud fail
	TEST_ASSERT(!libnapc_Writer_moveCurrentOffsetByAmount(&ctx, 6));
	// should work (position 0 -> 0 + 5 -> 5 which is less than 6)
	TEST_ASSERT(libnapc_Writer_moveCurrentOffsetByAmount(&ctx, 5));
	TEST_ASSERT(libnapc_Writer_getCurrentOffset(&ctx) == 5);

	// should work (sets position back to 0)
	TEST_ASSERT(libnapc_Writer_moveCurrentOffsetByAmount(&ctx, -5));
	TEST_ASSERT(libnapc_Writer_getCurrentOffset(&ctx) == 0);

	// should not work (would set position back to -1 which is invalid)
	TEST_ASSERT(!libnapc_Writer_moveCurrentOffsetByAmount(&ctx, -1));
	TEST_ASSERT(libnapc_Writer_getCurrentOffset(&ctx) == 0);
}
