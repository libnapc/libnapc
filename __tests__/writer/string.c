#include <napc.h>
#include <napc-testing.h>

TEST_CASE("should write strings correctly") {
	char data[6] = {1, 2, 3, 4, 5, 6};
	napc__Writer ctx;

	napc_Writer_init(&ctx, data, sizeof(data));

	TEST_ASSERT(
		napc_Writer_writeString(&ctx, "hello")
	);
	TEST_ASSERT(!napc_Writer_writeString(&ctx, "ab"));
	TEST_ASSERT(
		memcmp(data, "hello\x6", 6) == 0
	);
}
