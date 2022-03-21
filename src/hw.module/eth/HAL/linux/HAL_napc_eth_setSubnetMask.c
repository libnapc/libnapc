#if !defined(ARDUINO)
	#include <hw.module/eth/_private/_eth.h>

	void HAL_napc_eth_setSubnetMask(const napc_u8 *submask) {
		NAPC_IGNORE_VALUE(submask);
	}
#endif
