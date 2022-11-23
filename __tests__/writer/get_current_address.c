#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	unsigned char buffer[5];
	unsigned char *start = buffer;
	napc_u8 dummy_data[3] = {1,2,3};

	napc__Writer writer = napc_Writer_create(buffer, sizeof(buffer));

	TEST_ASSERT(
		napc_Writer_getCurrentAddress(&writer) == start
	);

	// Write 3 bytes
	NAPC_IGNORE_VALUE(
		napc_Writer_writeU8Array(&writer, 3, dummy_data)
	);

	TEST_ASSERT(
		napc_Writer_getCurrentAddress(&writer) == (start + 3)
	);
}
