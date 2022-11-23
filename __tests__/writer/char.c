#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should write chars correctly") {
	char data[4] = {0, 0, 0, 0xa};
	napc__Writer ctx;

	napc_Writer_init(&ctx, data, sizeof(data));

	TEST_ASSERT(napc_Writer_writeChar(&ctx, 'd'));
	TEST_ASSERT(napc_Writer_writeChar(&ctx, 'e'));
	TEST_ASSERT(napc_Writer_writeChar(&ctx, 'f'));
	TEST_ASSERT(napc_Writer_writeChar(&ctx, 'a'));
	TEST_ASSERT(!napc_Writer_writeChar(&ctx, 'b'));
	TEST_ASSERT(memcmp(data, "defa", 4) == 0);
}
