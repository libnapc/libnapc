#include <napc-serial/_private/_napc-serial.h>

void napc_unmute(void) {
	PV_napc_serial_muted = false;
}
