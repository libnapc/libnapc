#if !defined(ARDUINO)
	#include <hw.module/platform/linux/linux.h>
	#include <hw.module/udp/_private/_udp.h>

	bool HAL_napc_UDP_createSocket(void *ptr, napc_u16 port) {
		int sockfd = napc_linux__createUDPSocket();

		if (!napc_linux__bindSocket(sockfd, port)) {
			close(sockfd);

			return false;
		}

		int *tmp = ptr;
		*tmp = sockfd;

		return true;
	}
#endif
