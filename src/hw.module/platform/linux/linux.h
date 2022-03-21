#if !defined(NAPC_PLATFORM_LINUX_h)
	#define NAPC_PLATFORM_LINUX_h

	#if !defined(ARDUINO)
		#include <libnapc.h>

		#include <module/buffer/buffer.h>
		#include <module/ipv4participant/ipv4participant.h>

		#include <napc-utils/napc-utils.h> // napc_mzero()
		#include <sys/socket.h> // socket(), AF_INET, SOCK_DGRAM
		#include <netinet/in.h> // struct sockaddr_in
		#include <arpa/inet.h> // inet_ntoa()
		#include <unistd.h> // close()
		#include <fcntl.h> // fcntl()
		#include <signal.h> // signal(), SIGPIPE, SIG_IGN

		int napc_linux__createUDPSocket(void);
		struct sockaddr_in napc_linux__createAddressStruct(int port);
		bool napc_linux__bindSocket(int sockfd, int port);

		bool napc_linux__writeToUDPSocket(
			int sockfd,
			const void *buffer, napc_size buffer_size,
			napc__IPv4Participant destination
		);

		bool napc_linux__readFromUDPSocket(
			int sockfd,
			napc__Buffer *buffer,
			napc__IPv4Participant *source
		);
	#endif
#endif
