#include <libnapc-serial/_private/_libnapc-serial.h>

void libnapc_mute(void) {
	PV_libnapc_serial_muted = true;
}
