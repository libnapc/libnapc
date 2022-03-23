#include <hw.module/udp/_private/_udp.h>

void napc_UDP_closeSocket(napc__UDPSocket udp_socket) {
	void *element = napc_Pool_getAddress(&PV_napc_udp_sockets_pool, udp_socket);

	HAL_napc_UDP_closeSocket(element);

	napc_Pool_releaseElement(&PV_napc_udp_sockets_pool, udp_socket);
}
