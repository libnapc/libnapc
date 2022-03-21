#if !defined(ARDUINO)
	#include <hw.module/platform/linux/linux.h>

	struct sockaddr_in napc_linux__createAddressStruct(int port) {
		struct sockaddr_in addr;

		napc_mzero(&addr, sizeof(addr));

		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = INADDR_ANY;
		addr.sin_port = htons(port);

		return addr;
	}
#endif
