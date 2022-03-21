#include <hw.module/eth/_private/_eth.h>

void napc_eth_setSubnetMask(const char *submask) {
	PV_napc_eth_assertInitialized();

	napc_u8 bytes[4];

	if (!napc_parser_parseIPv4Address(submask, bytes)) {
		PV_NAPC_ETH_ERROR("Invalid Subnetmask '%s'", submask);

		return;
	}

	HAL_napc_eth_setSubnetMask(bytes);

	PV_NAPC_ETH_INFO("Set Subnetmask to '%s'", submask);
}
