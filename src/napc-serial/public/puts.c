#include <napc-serial/_private/_napc-serial.h>

void napc_puts(const char *str) {
	if (PV_napc_serial_muted) return;

	if (PV_napc_serial_available) {
		HAL_napc_puts(str);
	}
}
