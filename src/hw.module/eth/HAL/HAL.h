#if !defined(HAL_NAPC_MODULE_ETH_h)
	#define HAL_NAPC_MODULE_ETH_h

	#include <hw.module/eth/eth.h>

	void HAL_napc_initEthernet(void);

	bool HAL_napc_eth_getLinkStatus(void);

	void HAL_napc_eth_setMACAddress(const napc_u8 *mac);

	void HAL_napc_eth_setIPAddress(const napc_u8 *ip);
	void HAL_napc_eth_setSubnetMask(const napc_u8 *submask);
	void HAL_napc_eth_setGatewayAddress(const napc_u8 *ip);
#endif
