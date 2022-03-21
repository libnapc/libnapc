#include <napc-delay/_private/_napc-delay.h>

void napc_delay(napc_time amount) {
	HAL_napc_delay(amount);
}
