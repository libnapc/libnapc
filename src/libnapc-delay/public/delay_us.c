#include <libnapc-delay/_private/_libnapc-delay.h>

void libnapc_delayUs(libnapc_time amount) {
	HAL_libnapc_delayUs(amount);
}
