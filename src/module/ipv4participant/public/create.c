#include <module/ipv4participant/_private/_ipv4participant.h>

libnapc__IPv4Participant libnapc_IPv4Participant_create(const char *addr, libnapc_u16 port) {
	libnapc__IPv4Participant participant;

	libnapc_IPv4Participant_init(&participant, addr, port);

	return participant;
}
