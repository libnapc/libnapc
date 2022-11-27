#include <module/ipv4participant/_private/_ipv4participant.h>

void libnapc_IPv4Participant_copy(
	libnapc__IPv4Participant *dest,
	libnapc__IPv4Participant source
) {
	LIBNAPC_MAGIC_ASSERT(napc__IPv4Participant, &source);

	LIBNAPC_MAGIC_INIT(napc__IPv4Participant, dest);
	libnapc_strncpy(dest->addr, source.addr, sizeof(dest->addr));

	dest->port = source.port;
}
