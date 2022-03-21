#if !defined(ARDUINO)
	#include <hw.module/platform/linux/linux.h>

	int napc_linux__createUDPSocket(void) {
		int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

		if (0 > sockfd) {
			return -1;
		}

		int enable = 1;
		int result = setsockopt(
			sockfd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)
		);

		if (result != 0) {
			close(sockfd);

			return -1;
		}

		return sockfd;
	}
#endif
