#include <module/ipv4participant/_private/_ipv4participant.h>

void libnapc_IPv4Participant_init(
	libnapc__IPv4Participant *participant,
	const char *addr, libnapc_u16 port
) {
	LIBNAPC_MAGIC_INIT(napc__IPv4Participant, participant);

	libnapc_strncpy(participant->addr, addr, sizeof(participant->addr));
	participant->port = port;
}
