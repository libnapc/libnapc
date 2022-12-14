#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should write string formats correctly") {
	char data[6] = {1, 2, 3, 4, 5, 6};
	libnapc__Writer ctx;

	libnapc_Writer_init(&ctx, data, sizeof(data));

	TEST_ASSERT(
		libnapc_Writer_writeStringFormat(&ctx, "%2.2x %d", 0xef, -4)
	);
	TEST_ASSERT(
		memcmp(data, "ef -4\x6", 6) == 0
	);
}
