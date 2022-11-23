#include <napc-delay/_private/_napc-delay.h>

void libnapc_delay(napc_time amount) {
	HAL_libnapc_delay(amount);
}
