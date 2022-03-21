#include <hw.module/eth/_private/_eth.h>

void PV_napc_eth_assertInitialized(void) {
	if (!PV_napc_eth_initialized) {
		NAPC_PANIC(
			"Attempted to use ethernet module without ethernet being initialized."
		);
	}
}
