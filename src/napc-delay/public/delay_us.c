#include <napc-delay/_private/_napc-delay.h>

void napc_delayUs(napc_time amount) {
	HAL_napc_delayUs(amount);
}
