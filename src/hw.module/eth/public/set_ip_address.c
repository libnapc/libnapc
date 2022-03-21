#include <hw.module/eth/_private/_eth.h>

void napc_eth_setIPAddress(const char *ip) {
	PV_napc_eth_assertInitialized();

	napc_u8 bytes[4];

	if (!napc_parser_parseIPv4Address(ip, bytes)) {
		PV_NAPC_ETH_ERROR("Invalid IP-Address '%s'", ip);

		return;
	}

	HAL_napc_eth_setIPAddress(bytes);

	PV_NAPC_ETH_INFO("Set IP-Address to '%s'", ip);
}
