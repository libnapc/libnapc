#include <napc.h>

napc__UDPSocket sock;
int counter = 0;

void napc_setup(const char *p) {
	if (!napc_env_isEthernetAvailable()) {
		NAPC_PANIC("Sorry, ethernet is not available :(\n");
	}

	// initialize ethernet
	napc_eth_setIPAddress("192.168.0.20");
	napc_eth_setMACAddress("aa:bb:cc:dd:ee:ff");

	// open udp socket on port 2020
	sock = napc_UDP_createSocket(2020);

	napc_printf("Opened UDP socket on port 2020\n");
}

bool napc_loop(napc_time uptime) {
	char packet_buffer[512];

	napc__Buffer buffer = napc_Buffer_create(packet_buffer, sizeof(packet_buffer));
	napc__IPv4Participant source_ip;

	if (napc_UDP_receive(sock, &source_ip, &buffer)) {
		napc_printf(
			"Received %" NAPC_SIZE_PRINTF " bytes from %s:%u\n",
			buffer.size,
			source_ip.addr,
			source_ip.port
		);

		napc_UDP_send(sock, source_ip, buffer.data, buffer.size);
	}

	return true;
}
