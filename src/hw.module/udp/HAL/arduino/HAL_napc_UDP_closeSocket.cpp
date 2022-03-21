#if defined(ARDUINO)
	#include <hw.module/platform/arduino/arduino.hpp>

	extern "C" {
		#include <hw.module/udp/_private/_udp.h>

		void HAL_napc_UDP_closeSocket(void *ptr) {
			EthernetUDP *udp = (EthernetUDP *)ptr;

			udp->stop();
		}
	}
#endif
