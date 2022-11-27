#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	unsigned char buffer[5];

	napc__Reader reader;

	libnapc_Reader_init(&reader, buffer, sizeof(buffer));

	TEST_ASSERT(
		libnapc_Reader_getRemainingBytes(&reader) == 5
	);

	// Advance by 3 bytes
	LIBNAPC_IGNORE_VALUE(
		libnapc_Reader_readU8Array(&reader, 3, NULL)
	);

	TEST_ASSERT(
		libnapc_Reader_getRemainingBytes(&reader) == 2
	);

	// Advance by 2 bytes
	LIBNAPC_IGNORE_VALUE(
		libnapc_Reader_readU8Array(&reader, 2, NULL)
	);

	TEST_ASSERT(
		libnapc_Reader_getRemainingBytes(&reader) == 0
	);
}
