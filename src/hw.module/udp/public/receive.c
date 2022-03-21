#include <hw.module/udp/_private/_udp.h>

bool napc_UDP_receive(
	napc__UDPSocket udp_socket,
	napc__IPv4Participant *source,
	napc__Buffer *out
) {
	if (source) {
	// do not check source, we don't expect it to be initialized here
	//	NAPC_MAGIC_ASSERT(napc__IPv4Participant, source);
	}
	NAPC_MAGIC_ASSERT(napc__Buffer, out);

	void *element = napc_Pool_getAddress(&PV_napc_udp_sockets_pool, udp_socket);

	return HAL_napc_UDP_receive(
		element, source, out
	);
}
