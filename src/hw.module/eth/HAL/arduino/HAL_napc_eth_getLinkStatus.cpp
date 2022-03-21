#if defined(ARDUINO)
	#include <Ethernet.h>

	extern "C" {
		#include <hw.module/eth/_private/_eth.h>

		bool HAL_napc_eth_getLinkStatus(void) {
			return Ethernet.linkStatus() == LinkON;
		}
	}
#endif
