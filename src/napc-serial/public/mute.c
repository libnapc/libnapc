#include <napc-serial/_private/_napc-serial.h>

void libnapc_mute(void) {
	PV_napc_serial_muted = true;
}
