#if !defined(ARDUINO)
	#include <hw.module/eth/_private/_eth.h>

	void HAL_napc_eth_setMACAddress(const napc_u8 *mac) {
		NAPC_IGNORE_VALUE(mac);
	}
#endif
