#include <module/random/_private/_random.h>

void napc_random_getRandomBytesSync(napc_size n_bytes, napc_u8 *out) {
	while (true) {
		bool result = napc_random_getRandomBytes(n_bytes, out);

		if (result) break;

		napc_random_collectBytes();

		napc_delayUs(125);
	}
}
