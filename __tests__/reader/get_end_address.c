#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	unsigned char buffer[5];
	unsigned char *end = buffer + 4;

	libnapc__Reader reader;

	libnapc_Reader_init(&reader, buffer, sizeof(buffer));

	TEST_ASSERT(
		libnapc_Reader_getEndAddress(&reader) == end
	);
}
