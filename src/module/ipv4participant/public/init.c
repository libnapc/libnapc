#include <module/ipv4participant/_private/_ipv4participant.h>

void napc_IPv4Participant_init(
	napc__IPv4Participant *participant,
	const char *addr, libnapc_u16 port
) {
	LIBNAPC_MAGIC_INIT(napc__IPv4Participant, participant);

	libnapc_strncpy(participant->addr, addr, NAPC_MODULE_NET_IP_STR_MAX);
	participant->port = port;
}
