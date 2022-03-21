#if !defined(ARDUINO)
	#include <hw.module/eth/_private/_eth.h>

	void HAL_napc_initEthernet(void) {
		PV_napc_eth_initialized = true;
	}
#endif
