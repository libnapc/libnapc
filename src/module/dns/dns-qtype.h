#if !defined(LIBNAPC_MODULE_DNS_QTYPE_h)
	#define LIBNAPC_MODULE_DNS_QTYPE_h

	#include <libnapc-internal.h>

	/*!
	 * @module DNS
	 * @type type:enum
	 * @fullname libnapc__DNSQType
	 * @brief Representation of DNS query type.
	 * @version 2.0.0
	 * @enum LIBNAPC_DNS_QTYPE_A A-Record query
	 * @enum LIBNAPC_DNS_QTYPE_CNAME CNAME-Record query
	 * @enum LIBNAPC_DNS_QTYPE_MX MX-Record query
	 * @enum LIBNAPC_DNS_QTYPE_TXT TXT-Record query
	 * @enum LIBNAPC_DNS_QTYPE_AAAA AAAA-Record query
	 * @changelog 2.0.0 added initial version
	 */
	typedef enum libnapc__DNSQType {
		LIBNAPC_DNS_QTYPE_A     = 1,
		LIBNAPC_DNS_QTYPE_CNAME = 5,
		LIBNAPC_DNS_QTYPE_MX    = 15,
		LIBNAPC_DNS_QTYPE_TXT   = 16,
		LIBNAPC_DNS_QTYPE_AAAA  = 28
	} libnapc__DNSQType;
#endif
