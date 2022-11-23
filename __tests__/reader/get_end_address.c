#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	unsigned char buffer[5];
	unsigned char *end = buffer + 4;

	napc__Reader reader;

	napc_Reader_init(&reader, buffer, sizeof(buffer));

	TEST_ASSERT(
		napc_Reader_getEndAddress(&reader) == end
	);
}
