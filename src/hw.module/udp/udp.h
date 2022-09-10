/*!
 * @name UDP:intro
 * @brief Send & receive network packets
 * @description
 * Used to send and/or receive IP packets over the UDP protocol.
 * @example
 * #include <napc.h>
 *
 * napc__UDPSocket sock;
 * int counter = 0;
 *
 * void napc_setup(const char *p) {
 * 	if (!napc_env_isEthernetAvailable()) {
 * 		NAPC_PANIC("Sorry, ethernet is not available :(\n");
 * 	}
 *
 * 	// initialize ethernet
 * 	napc_eth_setIPAddress("192.168.0.20");
 * 	napc_eth_setMACAddress("aa:bb:cc:dd:ee:ff");
 *
 * 	// open udp socket on port 2020
 * 	sock = napc_UDP_createSocket(2020);
 *
 * 	napc_printf("Opened UDP socket on port 2020\n");
 * }
 *
 * bool napc_loop(napc_time uptime) {
 * 	char packet_buffer[512];
 *
 * 	napc__Buffer buffer = napc_Buffer_create(packet_buffer, sizeof(packet_buffer));
 * 	napc__IPv4Participant source_ip;
 *
 * 	if (napc_UDP_receive(sock, &source_ip, &buffer)) {
 * 		napc_printf(
 * 			"Received %" NAPC_SIZE_PRINTF " bytes from %s:%u\n",
 * 			buffer.size,
 * 			source_ip.addr,
 * 			source_ip.port
 * 		);
 *
 * 		napc_UDP_send(sock, source_ip, buffer.data, buffer.size);
 * 	}
 *
 * 	return true;
 * }
 */
#if !defined(NAPC_HW_MODULE_UDP_h)
	#define NAPC_HW_MODULE_UDP_h

	#include <libnapc.h>

	#include <module/ipv4participant/ipv4participant.h>
	#include <module/buffer/buffer.h>

	/*!
	 * @name napc__UDPSocket
	 * @brief Representation of a UDP-Socket.
	 * @version 1.0.0
	 * @opaque
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef napc_ssize napc__UDPSocket;

	/*!
	 * @name napc_UDP_createSocket
	 * @brief Open an UDP-Socket.
	 * @version 1.0.0
	 * @description
	 * Open an UDP-socket on port `port` for receiving and sending messages.
	 * @param port IPv4 port number.
	 * @return Returns a negative number if socket could not be created.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc__UDPSocket udp_sock = napc_UDP_createSocket(2020);
	 * 
	 * if (0 > udp_sock) {
	 *     NAPC_PANIC("Failed to create UDP-socket.");
	 * }
	 */
	napc__UDPSocket napc_UDP_createSocket(napc_u16 port);

	/*!
	 * @name napc_UDP_receive
	 * @brief Receive an UDP-message.
	 * @version 1.0.0
	 * @description
	 * Receive a message on a UDP socket.
	 * @param udp_socket The UDP socket to receive from.
	 * @param source Source of received message (optional).
	 * @param out Pointer to a buffer to place received message.
	 * @return Returns `false` if no message was received.
	 * @warning It's not possible to receive a UDP packet with a size greater than `1500` bytes (MTU limit).
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char message_buffer[512];
	 * napc__Buffer buf;
	 * 
	 * napc__UDPSocket udp_socket = napc_UDP_createSocket(2020);
	 * 
	 * napc_Buffer_init(&buf, message_buffer, sizeof(message_buffer));
	 * 
	 * if (napc_UDP_receive(&udp_socket, NULL, &buf)) {
	 *     napc_printf("Received %" NAPC_SIZE_PRINTF " bytes\n", buf.size);
	 * }
	 */
	bool napc_UDP_receive(
		napc__UDPSocket udp_socket,
		napc__IPv4Participant *source,
		napc__Buffer *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_UDP_send
	 * @brief Send an UPD-message.
	 * @version 1.0.0
	 * @description
	 * Send a UDP message to `destination`.
	 * @param udp_socket The UDP socket to write the message to.
	 * @param destination IPv4 destination (ip & port).
	 * @param buffer Message to be sent.
	 * @param buffer_size Size of the message.
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning It's not possible to send UDP packets with a size greater than `1500` bytes (MTU limit).
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_UDP_send(
		napc__UDPSocket udp_socket,
		napc__IPv4Participant destination,
		const void *buffer, napc_size buffer_size
	);

	/*!
	 * @name napc_UDP_sendSilent
	 * @brief Send an UDP-message.
	 * @version 1.0.0
	 * @description
	 * Same as `napc_UDP_send()` but does not log anything.
	 * Used to send log over the network to another device.
	 * @param udp_socket The UDP socket to write the message to.
	 * @param destination IPv4 destination (ip & port).
	 * @param buffer Message to be sent.
	 * @param buffer_size Size of the message.
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning It's not possible to send UDP packets with a size greater than `1500` bytes (MTU limit).
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_UDP_sendSilent(
		napc__UDPSocket udp_socket,
		napc__IPv4Participant destination,
		const void *buffer, napc_size buffer_size
	);

	/*!
	 * @name napc_UDP_closeSocket
	 * @brief Close an open UDP-socket.
	 * @version 1.0.0
	 * @description
	 * Close an open UDP-socket.
	 * @param udp_socket The UDP-socket to be closed.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void napc_UDP_closeSocket(napc__UDPSocket udp_socket);

	/*!
	 * @name napc_UDP_getNumOpenSockets
	 * @brief Get the number of open UDP sockets.
	 * @version 1.0.0
	 * @description
	 * Gets the number of currently open UDP sockets.
	 * @return Returns the number of open UDP sockets.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_size napc_UDP_getNumOpenSockets(void);
#endif
