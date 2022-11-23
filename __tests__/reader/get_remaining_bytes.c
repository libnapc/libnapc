#include <napc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	unsigned char buffer[5];

	napc__Reader reader;

	napc_Reader_init(&reader, buffer, sizeof(buffer));

	TEST_ASSERT(
		napc_Reader_getRemainingBytes(&reader) == 5
	);

	// Advance by 3 bytes
	NAPC_IGNORE_VALUE(
		napc_Reader_readU8Array(&reader, 3, NULL)
	);

	TEST_ASSERT(
		napc_Reader_getRemainingBytes(&reader) == 2
	);

	// Advance by 2 bytes
	NAPC_IGNORE_VALUE(
		napc_Reader_readU8Array(&reader, 2, NULL)
	);

	TEST_ASSERT(
		napc_Reader_getRemainingBytes(&reader) == 0
	);
}
