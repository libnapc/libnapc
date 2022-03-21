#if !defined(PV_NAPC_HW_MODULE_ETH_h)
	#define PV_NAPC_HW_MODULE_ETH_h

	#include <hw.module/eth/eth.h>
	#include <hw.module/eth/HAL/HAL.h>
	#include <hw.module/eth/_private/_log.h>

	#include <napc-panic/napc-panic.h>
	#include <module/parser/parser.h> // napc_parser__parseMACAddress(), napc_parser__parseIPv4Address()

	extern bool PV_napc_eth_initialized; // @global

	/**
	 * Asserts if ethernet was properly initialized on boot.
	 */
	void PV_napc_eth_assertInitialized(void);
#endif
