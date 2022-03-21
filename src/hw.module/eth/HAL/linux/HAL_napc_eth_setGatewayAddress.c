#if !defined(ARDUINO)
	#include <hw.module/eth/_private/_eth.h>

	void HAL_napc_eth_setGatewayAddress(const napc_u8 *ip) {
		NAPC_IGNORE_VALUE(ip);
	}
#endif
