#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_reader__testCase79(void) {
    napc_unmute();
    napc_puts("[reader/get_address.c] should work as expected ... ");
    napc_mute();
	unsigned char buffer[5];
	unsigned char *start = buffer;

	napc__Reader reader;

	napc_Reader_init(&reader, buffer, sizeof(buffer));

	TEST_ASSERT(
		napc_Reader_getCurrentAddress(&reader) == start
	);

	// Read 3 bytes
	NAPC_IGNORE_VALUE(
		napc_Reader_readU8Array(&reader, 3, NULL)
	);

	TEST_ASSERT(
		napc_Reader_getCurrentAddress(&reader) == (start + 3)
	);
}
