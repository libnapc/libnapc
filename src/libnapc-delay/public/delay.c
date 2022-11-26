#include <libnapc-delay/_private/_libnapc-delay.h>

void libnapc_delay(libnapc_time amount) {
	HAL_libnapc_delay(amount);
}
