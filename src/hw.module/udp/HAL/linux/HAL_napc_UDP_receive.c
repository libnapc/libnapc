#if !defined(ARDUINO)
	#include <hw.module/platform/linux/linux.h>
	#include <hw.module/udp/_private/_udp.h>

	bool HAL_napc_UDP_receive(
		void *ptr,
		napc__IPv4Participant *source,
		napc__Buffer *out
	) {
		napc__IPv4Participant tmp_source;

		int sockfd = *((int *)ptr);

		if (!napc_linux__readFromUDPSocket(sockfd, out, &tmp_source)) {
			return false;
		}

		PV_napc_UDP_logMessage(
			false,
			tmp_source.addr,
			tmp_source.port,
			out->size
		);

		if (source) {
			napc_IPv4Participant_copy(source, tmp_source);
		}

		return true;
	}
#endif
