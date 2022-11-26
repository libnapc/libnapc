#if !defined(LIBNAPC_MODULE_DNS_QTYPE_h)
	#define LIBNAPC_MODULE_DNS_QTYPE_h

	#include <libnapc-internal.h>

	/*!
	 * @name napc__DNSQType
	 * @module DNS
	 * @brief Representation of DNS query type.
	 * @version 1.0.0
	 * @enum NAPC_DNS_QTYPE_A A-Record query
	 * @enum NAPC_DNS_QTYPE_CNAME CNAME-Record query
	 * @enum NAPC_DNS_QTYPE_MX MX-Record query
	 * @enum NAPC_DNS_QTYPE_TXT TXT-Record query
	 * @enum NAPC_DNS_QTYPE_AAAA AAAA-Record query
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @changelog 2.0.0 14.04.2022 added CNAME,MX and TXT types
	 */
	typedef enum napc__DNSQType {
		NAPC_DNS_QTYPE_A     = 1,
		NAPC_DNS_QTYPE_CNAME = 5,
		NAPC_DNS_QTYPE_MX    = 15,
		NAPC_DNS_QTYPE_TXT   = 16,
		NAPC_DNS_QTYPE_AAAA  = 28
	} napc__DNSQType;
#endif
