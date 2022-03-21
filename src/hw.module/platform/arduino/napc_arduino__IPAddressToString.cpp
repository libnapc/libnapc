#if defined(ARDUINO)
	#include <hw.module/platform/arduino/arduino.hpp>

	extern "C" {
		static char _ip_buf[64u]; // @static

		const char *napc_arduino__IPAddressToString(
			const arduino::IPAddress &address
		) {
			arduino::String s = (String(address[0]) + "." + address[1] + "." + address[2] + "." + address[3]);

			napc_strncpy(_ip_buf, s.c_str(), sizeof(_ip_buf));

			return _ip_buf;
		}
	}
#endif
