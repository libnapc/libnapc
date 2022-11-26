#include <napc-serial/_private/_napc-serial.h>

void libnapc_mute(void) {
	PV_libnapc_serial_muted = true;
}
