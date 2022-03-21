#if !defined(ARDUINO)
	#include <hw.module/platform/linux/linux.h>
	#include <hw.module/udp/_private/_udp.h>

	bool HAL_napc_UDP_send(
		void *ptr,
		bool do_logging,
		napc__IPv4Participant destination,
		const void *buffer, napc_size buffer_size
	) {
		int sockfd = *((int *)ptr);

		if (do_logging) {
			PV_napc_UDP_logMessage(
				true, destination.addr, destination.port, buffer_size
			);
		}

		return napc_linux__writeToUDPSocket(
			sockfd,
			buffer,
			buffer_size,
			destination
		);
	}
#endif
