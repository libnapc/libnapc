#include <hw.module/udp/_private/_udp.h>

napc__UDPSocket napc_UDP_createSocket(napc_u16 port) {
	if (!napc_env_isEthernetAvailable()) {
		NAPC_PANIC(
			"Attempted to create UDP socket without the system supporting ethernet."
		);
	}

	napc_ssize udp_socket = napc_Pool_claimElement(&PV_napc_udp_sockets_pool);

	if (0 > udp_socket) {
		return -1;
	}

	void *element = napc_Pool_getAddress(&PV_napc_udp_sockets_pool, udp_socket);

	if (!HAL_napc_UDP_createSocket(element, port)) {
		napc_Pool_releaseElement(&PV_napc_udp_sockets_pool, udp_socket);

		return -1;
	}

	return udp_socket;
}
