#include <hw.module/udp/_private/_udp.h>

napc_size napc_UDP_getNumOpenSockets(void) {
	napc_size count = 0;

	for (napc_size i = 0; i < PV_napc_udp_sockets_pool.num_elements; ++i) {
		bool open = napc_Pool_isClaimed(&PV_napc_udp_sockets_pool, i);

		if (open) {
			++count;
		}
	}

	return count;
}
