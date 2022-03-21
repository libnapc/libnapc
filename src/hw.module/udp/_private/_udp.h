#if !defined(PV_NAPC_HW_MODULE_UDP_h)
	#define PV_NAPC_HW_MODULE_UDP_h

	#include <hw.module/udp/udp.h>
	#include <hw.module/udp/HAL/HAL.h>
	#include <hw.module/udp/_private/_log.h>

	#include <hw.module/env/env.h>
	#include <module/pool/pool.h>
	#include <napc-utils/napc-utils.h>

	extern napc__Pool PV_napc_udp_sockets_pool; // @global

	void PV_napc_UDP_logMessage(
		bool sending,
		const char *ip,
		napc_u16 port,
		napc_size packet_size
	);
#endif
