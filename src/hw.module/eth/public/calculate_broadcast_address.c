#include <hw.module/eth/_private/_eth.h>

static bool _validateSubnetMask(const napc_u8 *octets) {
	napc_u32 mask = (
		octets[0] << 24u |
		octets[1] << 16u |
		octets[2] <<  8u |
		octets[3] <<  0u
	);

	// https://stackoverflow.com/a/45640597/2005038
	if (mask == 0) {
		PV_NAPC_ETH_ERROR("Invalid subnet mask detected.");
		return false;
	} else if (mask & (~mask >> 1)) {
		PV_NAPC_ETH_ERROR("Invalid subnet mask detected.");
		return false;
	}

	return true;
}


bool napc_eth_calculateBroadcastAddress(
	const char *ip,
	const char *submask,
	char *out, napc_size out_size
) {
	napc_u8 ip_bytes[4];
	napc_u8 submask_bytes[4];

	if (!napc_parser_parseIPv4Address(ip, ip_bytes)) {
		return false;
	} else if (!napc_parser_parseIPv4Address(submask, submask_bytes)) {
		return false;
	}

	napc__Writer wctx = napc_Writer_create(out, out_size, NAPC_WRITER_MODE_REGULAR);

	if (!_validateSubnetMask(submask_bytes)) {
		PV_NAPC_ETH_ERROR(
			"Cannot calculate broadcast address because subnetmask '%s' is invalid.",
			submask
		);

		return false;
	}

	// IP Adress (LOGICAL OR) INVERTED SUBMASK -> BROADCAST
	napc_u8 broadcast_address[4] = {
		ip_bytes[0] | (submask_bytes[0] ^ 0xFFu),
		ip_bytes[1] | (submask_bytes[1] ^ 0xFFu),
		ip_bytes[2] | (submask_bytes[2] ^ 0xFFu),
		ip_bytes[3] | (submask_bytes[3] ^ 0xFFu)
	};

	if (!napc_Writer_writeStringFormat(&wctx, "%d", broadcast_address[0])) return false;
	if (!napc_Writer_writeStringFormat(&wctx, ".%d", broadcast_address[1])) return false;
	if (!napc_Writer_writeStringFormat(&wctx, ".%d", broadcast_address[2])) return false;
	if (!napc_Writer_writeStringFormat(&wctx, ".%d", broadcast_address[3])) return false;
	if (!napc_Writer_writeChar(&wctx, 0)) return false;

	return true;
}
