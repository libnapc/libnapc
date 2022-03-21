#if !defined(NAPC_PLATFORM_ARDUINO_hpp)
	#define NAPC_PLATFORM_ARDUINO_hpp

	#if defined(ARDUINO)
		#include <Arduino.h>
		#include <Ethernet.h>
		#include <EthernetUdp.h>
		#include <SD.h>

		extern "C" {
			#include <napc-utils/napc-utils.h> // napc_strncpy()

			const char *napc_arduino__IPAddressToString(
				const arduino::IPAddress &address
			);
		}
	#endif
#endif
