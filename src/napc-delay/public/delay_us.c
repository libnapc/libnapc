#include <napc-delay/_private/_napc-delay.h>

void libnapc_delayUs(napc_time amount) {
	HAL_libnapc_delayUs(amount);
}
