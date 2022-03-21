#include <hw.module/env/_private/_env.h>

extern bool PV_napc_eth_initialized; // @global

bool napc_env_isEthernetAvailable(void) {
	return PV_napc_eth_initialized;
}
