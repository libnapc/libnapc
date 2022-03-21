#if !defined(ARDUINO)
	#include <hw.module/platform/linux/linux.h>

	bool napc_linux__readFromUDPSocket(
		int sockfd,
		napc__Buffer *buffer,
		napc__IPv4Participant *source
	) {
		struct sockaddr_in addr;
		socklen_t len = sizeof(addr);

		napc_mzero(&addr, sizeof(addr));

		napc_ssize result = (napc_ssize)recvfrom(
			sockfd,
			// buffer and size
			buffer->data, buffer->size,
			// flags
			MSG_DONTWAIT,
			(struct sockaddr *)&addr, &len
		);

		if (0 > result) {
			return false;
		}

		// Update buffer size
		buffer->size = result;

		napc_IPv4Participant_init(
			source,
			// IP-Address as string
			inet_ntoa(addr.sin_addr),
			// Port
			ntohs(addr.sin_port)
		);

		return true;
	}
#endif
