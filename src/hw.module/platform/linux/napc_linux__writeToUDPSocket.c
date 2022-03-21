#if !defined(ARDUINO)
	#include <hw.module/platform/linux/linux.h>

	bool napc_linux__writeToUDPSocket(
		int sockfd,
		const void *buffer, napc_size buffer_size,
		napc__IPv4Participant destination
	) {
		struct sockaddr_in addr = napc_linux__createAddressStruct(destination.port);
		addr.sin_addr.s_addr = inet_addr(destination.addr);

		(void)sendto(
			sockfd,
			// buffer, buffer size
			buffer, buffer_size,
			// flags
			0,
			(const struct sockaddr *)&addr, sizeof(addr)
		);

		return true;
	}
#endif
