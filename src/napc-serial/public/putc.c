#include <napc-serial/_private/_napc-serial.h>

void libnapc_putc(char ch) {
	if (PV_libnapc_serial_muted) return;

	if (PV_libnapc_serial_available) {
		HAL_libnapc_putc(ch);
	}
}
