#include <hw.module/udp/_private/_udp.h>

bool napc_UDP_sendSilent(
	napc__UDPSocket udp_socket,
	napc__IPv4Participant destination,
	const void *buffer, napc_size buffer_size
) {
	NAPC_MAGIC_ASSERT(napc__IPv4Participant, &destination);

	void *element = napc_Pool_getAddress(&PV_napc_udp_sockets_pool, udp_socket);

	return HAL_napc_UDP_send(
		element, false, destination, buffer, buffer_size
	);
}
