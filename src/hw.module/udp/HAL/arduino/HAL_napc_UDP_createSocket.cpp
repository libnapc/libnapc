#if defined(ARDUINO)
	#include <hw.module/platform/arduino/arduino.hpp>

	extern "C" {
		#include <hw.module/udp/_private/_udp.h>

		bool HAL_napc_UDP_createSocket(void *ptr, napc_u16 port) {
			EthernetUDP *udp = (EthernetUDP *)ptr;

			return udp->begin(port) == 1;
		}
	}
#endif
