#if !defined(ARDUINO)
	#include <hw.module/platform/linux/linux.h>

	bool napc_linux__bindSocket(int sockfd, int port) {
		struct sockaddr_in addr = napc_linux__createAddressStruct(port);

		int result = bind(
			sockfd, (const struct sockaddr *)&addr, sizeof(addr)
		);

		if (result != 0) {
			return false;
		}

		return true;
	}
#endif
