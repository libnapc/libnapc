#include <napc-rand-source/_private/_napc-rand-source.h>

bool napc_getRandomBit(bool *out, int source) {
	return HAL_napc_getRandomBit(out, source);
}
