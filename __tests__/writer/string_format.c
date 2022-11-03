#include <napc.h>
#include <napc-testing.h>

TEST_CASE("should write string formats correctly") {
	char data[6] = {1, 2, 3, 4, 5, 6};
	napc__Writer ctx;

	napc_Writer_init(&ctx, data, sizeof(data), NAPC_WRITER_MODE_REGULAR);

	TEST_ASSERT(
		napc_Writer_writeStringFormat(&ctx, "%2.2x %d", 0xef, -4)
	);
	TEST_ASSERT(
		memcmp(data, "ef -4\x6", 6) == 0
	);
}
