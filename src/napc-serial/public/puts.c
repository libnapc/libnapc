#include <napc-serial/_private/_napc-serial.h>

void libnapc_puts(const char *str) {
	if (PV_napc_serial_muted) return;

	if (PV_libnapc_serial_available) {
		HAL_libnapc_puts(str);
	}
}
