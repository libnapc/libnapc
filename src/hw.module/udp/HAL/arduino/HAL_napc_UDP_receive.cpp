#if defined(ARDUINO)
	#include <hw.module/platform/arduino/arduino.hpp>

	extern "C" {
		#include <hw.module/udp/_private/_udp.h>

		bool HAL_napc_UDP_receive(
			void *ptr,
			napc__IPv4Participant *source,
			napc__Buffer *out
		) {
			EthernetUDP *udp = (EthernetUDP *)ptr;

			napc_ssize available = (napc_ssize)udp->parsePacket();

			if (0 >= available) return false;

			PV_NAPC_UDP_DEBUG(
				"udp->parsePacket() says %" NAPC_SSIZE_PRINTF " bytes are available to read.",
				available
			);

			napc_ssize result = udp->read(
				(char *)out->data, out->size
			);

			if (0 > result) {
				return false;
			}

			// Update buffer size
			out->size = result;

			const char *remote_ip = napc_arduino__IPAddressToString(udp->remoteIP());
			napc_u16 remote_port = udp->remotePort();

			PV_napc_UDP_logMessage(
				false, remote_ip, remote_port, out->size
			);

			if (source) {
				napc_IPv4Participant_init(
					source,
					// IP-Address as string
					remote_ip,
					// Port
					remote_port
				);
			}

			return true;
		}
	}
#endif
