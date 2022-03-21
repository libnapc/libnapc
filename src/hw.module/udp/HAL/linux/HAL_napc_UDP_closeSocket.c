#if !defined(ARDUINO)
	#include <hw.module/platform/linux/linux.h>
	#include <hw.module/udp/_private/_udp.h>

	void HAL_napc_UDP_closeSocket(void *ptr) {
		int sockfd = *((int *)ptr);

		close(sockfd);
	}
#endif
