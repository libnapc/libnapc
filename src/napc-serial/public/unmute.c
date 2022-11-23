#include <napc-serial/_private/_napc-serial.h>

void libnapc_unmute(void) {
	PV_napc_serial_muted = false;
}
