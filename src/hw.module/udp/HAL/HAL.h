#if !defined(HAL_NAPC_HW_MODULE_UDP_h)
	#define HAL_NAPC_HW_MODULE_UDP_h

	#include <hw.module/udp/udp.h>

	void HAL_napc_UDP_initSocketPool(void);

	bool HAL_napc_UDP_createSocket(void *ptr, napc_u16 port);

	bool HAL_napc_UDP_receive(
		void *ptr,
		napc__IPv4Participant *source,
		napc__Buffer *out
	);

	bool HAL_napc_UDP_send(
		void *ptr,
		bool do_logging,
		napc__IPv4Participant destination,
		const void *buffer, napc_size buffer_size
	);

	void HAL_napc_UDP_closeSocket(void *ptr);
#endif
