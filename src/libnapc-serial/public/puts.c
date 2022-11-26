#include <libnapc-serial/_private/_libnapc-serial.h>

void libnapc_puts(const char *str) {
	if (PV_libnapc_serial_muted) return;

	if (PV_libnapc_serial_available) {
		HAL_libnapc_puts(str);
	}
}
