#include <module/ipv4participant/_private/_ipv4participant.h>

napc__IPv4Participant napc_IPv4Participant_create(const char *addr, libnapc_u16 port) {
	napc__IPv4Participant participant;

	napc_IPv4Participant_init(&participant, addr, port);

	return participant;
}
