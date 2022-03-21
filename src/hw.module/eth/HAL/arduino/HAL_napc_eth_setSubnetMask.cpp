#if defined(ARDUINO)
	#include <Ethernet.h>

	extern "C" {
		#include <hw.module/eth/_private/_eth.h>

		void HAL_napc_eth_setSubnetMask(const napc_u8 *submask) {
			Ethernet.setSubnetMask(submask);
		}
	}
#endif
