#include <napc-serial/_private/_napc-serial.h>

void napc_putc(char ch) {
	if (PV_napc_serial_muted) return;

	if (PV_napc_serial_available) {
		HAL_napc_putc(ch);
	}
}
