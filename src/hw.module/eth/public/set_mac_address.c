#include <hw.module/eth/_private/_eth.h>

void napc_eth_setMACAddress(const char *mac) {
	PV_napc_eth_assertInitialized();

	napc_u8 bytes[6];

	if (!napc_parser_parseMACAddress(mac, bytes)) {
		PV_NAPC_ETH_ERROR("Invalid MAC-Address '%s'", mac);

		return;
	}

	HAL_napc_eth_setMACAddress(bytes);

	PV_NAPC_ETH_INFO("Set MAC-Address to '%s'", mac);
}
