#if defined(ARDUINO)
	#include <hw.module/platform/arduino/arduino.hpp>

	extern "C" {
		#include <hw.module/udp/_private/_udp.h>

		bool HAL_napc_UDP_send(
			void *ptr,
			bool do_logging,
			napc__IPv4Participant destination,
			const void *buffer, napc_size buffer_size
		) {
			EthernetUDP *udp = (EthernetUDP *)ptr;

			if (do_logging) {
				PV_napc_UDP_logMessage(
					true,
					destination.addr,
					destination.port,
					buffer_size
				);
			}

			arduino::IPAddress IP;

			if (!IP.fromString(destination.addr)) {
				PV_NAPC_UDP_ERROR(
					"Failed to convert IP %s to raw IP-Address.",
					destination.addr
				);

				return false;
			}

			udp->beginPacket(
				IP, destination.port
			);
			udp->write(
				(const char *)buffer,
				buffer_size
			);

			if (udp->endPacket() != 1) {
				PV_NAPC_UDP_ERROR(
					"Failed to send UDP-Packet (size=%" NAPC_SIZE_PRINTF ") to %s:%u.",
					buffer_size, destination.addr, destination.port
				);

				return false;
			}

			return true;
		}
	}
#endif
