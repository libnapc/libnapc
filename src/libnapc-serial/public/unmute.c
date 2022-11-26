#include <libnapc-serial/_private/_libnapc-serial.h>

void libnapc_unmute(void) {
	PV_libnapc_serial_muted = false;
}
