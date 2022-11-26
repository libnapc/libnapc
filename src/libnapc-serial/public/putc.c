#include <libnapc-serial/_private/_libnapc-serial.h>

void libnapc_putc(char ch) {
	if (PV_libnapc_serial_muted) return;

	if (PV_libnapc_serial_available) {
		HAL_libnapc_putc(ch);
	}
}
