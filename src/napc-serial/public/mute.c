#include <napc-serial/_private/_napc-serial.h>

void napc_mute(void) {
	PV_napc_serial_muted = true;
}
