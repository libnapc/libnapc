#if !defined(NAPC_MODULE_DNS_QTYPE_h)
	#define NAPC_MODULE_DNS_QTYPE_h

	#include <libnapc.h>

	/*!
	 * @name napc__DNSQType
	 * @brief Representation of DNS query type.
	 * @version 1.0.0
	 * @enum NAPC_DNS_QTYPE_A A-Record query
	 * @enum NAPC_DNS_QTYPE_AAAA AAAA-Record query
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef enum {
		NAPC_DNS_QTYPE_A    = 1,
		NAPC_DNS_QTYPE_AAAA = 28
	} napc__DNSQType;
#endif
