#if !defined(ARDUINO)
	#include <hw.module/platform/linux/linux.h>
	#include <hw.module/udp/_private/_udp.h>

	static int _udp_sockets[5]; // @static

	void HAL_napc_UDP_initSocketPool(void) {
		napc_Pool_init(
			&PV_napc_udp_sockets_pool,
			"UDPSocket",
			_udp_sockets,
			sizeof(_udp_sockets) / sizeof(int),
			sizeof(int)
		);
	}
#endif
