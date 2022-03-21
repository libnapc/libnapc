#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

static napc_ssize _readFunction(const void *data, napc_size data_size, void *context) {
	(void)data;
	(void)data_size;
	(void)context;

	return 31;
}

void PV_napc_misc__testCase11(void) {
    napc_unmute();
    napc_puts("[misc/impartial.c] should return false on impartial operation ... ");
    napc_mute();
	napc_u8 data[64];

	TEST_ASSERT(
		!napc_misc_chunkedOperation(
			data, sizeof(data), 32, _readFunction, NULL
		)
	);
}
