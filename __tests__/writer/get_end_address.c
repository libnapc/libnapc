#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	unsigned char buffer[5];
	unsigned char *end = buffer + 4;

	napc__Writer writer = napc_Writer_create(buffer, sizeof(buffer));

	TEST_ASSERT(
		napc_Writer_getEndAddress(&writer) == end
	);
}
