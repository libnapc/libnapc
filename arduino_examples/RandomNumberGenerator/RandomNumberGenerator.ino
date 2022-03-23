#include <napc.h>

napc_u8 random_bytes[16];

void napc_app_setup(const char *platform) {
	napc_printf("Random numbers are being generated please wait\n");
}

bool napc_app_loop(napc_time uptime) {
	// request of 16 random bytes
	if (napc_random_getRandomBytes(16, random_bytes)) {
		// do something with random_bytes

		napc_printf("Here are your random numbers: ");

		for (int i = 0; i < 16; ++i) {
			napc_printf("%2.2x", random_bytes[i]);
		}

		napc_printf("\n");

		return false;
	}

	// collect new random data
	napc_random_collectBytes();

	return true;
}
