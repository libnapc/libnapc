#if !defined(NAPC_HW_MODULE_ETH_h)
	#define NAPC_HW_MODULE_ETH_h

	#include <libnapc.h>

	/*!
	 * @name napc_eth_getLinkStatus
	 * @brief Get the link status of network adapter.
	 * @version 1.0.0
	 * @return Returns `true` if ethernet link is established, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * if (napc_eth_getLinkStatus()) {
	 *     napc_printf("Ethernet link established.\n");
	 * }
	 */
	bool napc_eth_getLinkStatus(void) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_eth_setMACAddress
	 * @brief Set mac address of network adapter.
	 * @version 1.0.0
	 * @param mac MAC-Address in format `aa:bb:cc:dd:ee:ff`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_eth_setMACAddress("88:24:D3:27:9A:2F");
	 */
	void napc_eth_setMACAddress(const char *mac);

	/*!
	 * @name napc_eth_setIPAddress
	 * @brief Set ip address of network adapter.
	 * @version 1.0.0
	 * @param ip IPv4-Address in format `a.b.c.d`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_eth_setIPAddress("192.168.1.50");
	 */
	void napc_eth_setIPAddress(const char *ip);

	/*!
	 * @name napc_eth_setSubnetMask
	 * @brief Set subnetmask of network adapter.
	 * @version 1.0.0
	 * @param submask Subnetmask in format `a.b.c.d`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_eth_setSubnetMask("255.255.255.0");
	 */
	void napc_eth_setSubnetMask(const char *submask);

	/*!
	 * @name napc_eth_setGatewayAddress
	 * @brief Set the gateway address of network adapter.
	 * @version 1.0.0
	 * @param ip IPv4-Address in format `a.b.c.d`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_eth_setGatewayAddress("192.168.1.1");
	 */
	void napc_eth_setGatewayAddress(const char *ip);

	/*!
	 * @name napc_eth_calculateBroadcastAddress
	 * @brief Calulcate broadcast address of IP-address.
	 * @version 2.0.0
	 * @param ip IPv4-Address in format `a.b.c.d`.
	 * @param submask IPv4-Subnetmask in format `a.b.c.d`.
	 * @param out Output array.
	 * @param out_size Size of output array.
	 * @changelog 2.0.0 12.04.2022 initial version
	 * @example
	 * char broadcast_addr[32];
	 * 
	 * bool result = napc_eth_calculateBroadcastAddress(
	 *     "10.1.2.5",
	 *     "255.255.255.0",
	 *     broadcast_addr, sizeof(broadcast_addr)
	 * );
	 * 
	 * if (result) {
	 *     napc_printf("Broadcast address of 10.1.2.5 is %s\n", broadcast_addr);
	 * }
	 */
	bool napc_eth_calculateBroadcastAddress(
		const char *ip,
		const char *submask,
		char *out, napc_size out_size
	) NAPC_FN_WARNUNUSED_RET();
#endif
