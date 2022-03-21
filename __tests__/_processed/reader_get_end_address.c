#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_reader__testCase70(void) {
    napc_unmute();
    napc_puts("[reader/get_end_address.c] should work as expected ... ");
    napc_mute();
	unsigned char buffer[5];
	unsigned char *end = buffer + 4;

	napc__Reader reader;

	napc_Reader_init(&reader, buffer, sizeof(buffer));

	TEST_ASSERT(
		napc_Reader_getEndAddress(&reader) == end
	);
}
