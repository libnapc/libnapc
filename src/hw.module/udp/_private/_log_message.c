#include <hw.module/udp/_private/_udp.h>

void PV_napc_UDP_logMessage(
	bool sending,
	const char *ip,
	napc_u16 port,
	napc_size packet_size
) {
	const char *verb1 = sending ? "Sending" : "Received";
	const char *verb2 = sending ? "to" : "from";

	PV_NAPC_UDP_DEBUG(
		"%s UDP-Message %s %s:%u (packet_size=%" NAPC_SIZE_PRINTF ")",
		verb1, verb2, ip, port, packet_size
	);
}
