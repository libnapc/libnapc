#if defined(ARDUINO)
	#include <Ethernet.h>

	extern "C" {
		#include <hw.module/eth/_private/_eth.h>

		void HAL_napc_eth_setIPAddress(const napc_u8 *ip) {
			Ethernet.setLocalIP(ip);
		}
	}
#endif
