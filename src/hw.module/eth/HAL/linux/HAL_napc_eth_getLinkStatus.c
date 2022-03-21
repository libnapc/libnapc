#if !defined(ARDUINO)
	#include <hw.module/eth/_private/_eth.h>
	#include <stdlib.h> // getenv()
	#include <unistd.h> // access()

	bool HAL_napc_eth_getLinkStatus(void) {
		const char *LINK_STATUS_FILE = getenv("NAPC_ETH_LINK_STATUS_FILE");

		if (LINK_STATUS_FILE) {
			return access(LINK_STATUS_FILE, F_OK) == 0;
		}

		return true;
	}
#endif
