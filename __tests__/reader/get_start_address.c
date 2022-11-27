#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	unsigned char buffer[5];
	unsigned char *start = buffer;

	napc__Reader reader = libnapc_Reader_create(buffer, sizeof(buffer));

	// Read 3 bytes
	LIBNAPC_IGNORE_VALUE(libnapc_Reader_readU8Array(&reader, 3, NULL));

	TEST_ASSERT(
		libnapc_Reader_getStartAddress(&reader) == start
	);
}
