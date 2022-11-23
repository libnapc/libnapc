#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	unsigned char buffer[5];
	unsigned char *start = buffer;

	napc__Reader reader = napc_Reader_create(buffer, sizeof(buffer));

	// Read 3 bytes
	NAPC_IGNORE_VALUE(napc_Reader_readU8Array(&reader, 3, NULL));

	TEST_ASSERT(
		napc_Reader_getStartAddress(&reader) == start
	);
}
