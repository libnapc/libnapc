#include <module/ipv4participant/_private/_ipv4participant.h>

void napc_IPv4Participant_copy(
	napc__IPv4Participant *dest,
	napc__IPv4Participant source
) {
	NAPC_MAGIC_ASSERT(napc__IPv4Participant, &source);

	NAPC_MAGIC_INIT(napc__IPv4Participant, dest);
	libnapc_strncpy(dest->addr, source.addr, NAPC_MODULE_NET_IP_STR_MAX);

	dest->port = source.port;
}
