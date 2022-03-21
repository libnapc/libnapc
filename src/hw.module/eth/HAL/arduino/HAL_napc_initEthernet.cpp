#if defined(ARDUINO)
	#include <Ethernet.h>

	extern "C" {
		#include <hw.module/eth/_private/_eth.h>

		static napc_u8 _dummy_mac_address[6] = {
			0x11, 0x22, 0x33, 0x44, 0x55, 0x66
		};

		// use an ip from the self assigned ip range to suppress the dhcp client
		static napc_u8 _self_assigned_ip[4] = {169, 254, 99, 99};

		void HAL_napc_initEthernet(void) {
			Ethernet.begin(_dummy_mac_address, _self_assigned_ip);

			if (Ethernet.hardwareStatus() == EthernetNoHardware) {
				PV_NAPC_ETH_WARNING("Ethernet shield was not found.");
			} else if (Ethernet.hardwareStatus() == EthernetW5100) {
				PV_NAPC_ETH_INFO("W5100 Ethernet controller detected.");

				PV_napc_eth_initialized = true;
			} else if (Ethernet.hardwareStatus() == EthernetW5200) {
				PV_NAPC_ETH_INFO("W5200 Ethernet controller detected.");

				PV_napc_eth_initialized = true;
			} else if (Ethernet.hardwareStatus() == EthernetW5500) {
				PV_NAPC_ETH_INFO("W5500 Ethernet controller detected.");

				PV_napc_eth_initialized = true;
			}
		}
	}
#endif
