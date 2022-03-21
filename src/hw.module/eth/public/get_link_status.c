#include <hw.module/eth/_private/_eth.h>

bool napc_eth_getLinkStatus(void) {
	PV_napc_eth_assertInitialized();

	return HAL_napc_eth_getLinkStatus();
}
