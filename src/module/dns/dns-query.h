#if !defined(LIBNAPC_MODULE_DNS_QUERY_h)
	#define LIBNAPC_MODULE_DNS_QUERY_h

	#include <libnapc-internal.h>
	#include <module/dns/dns-qtype.h>

	#define NAPC_MODULE_DNS_MAX_NAME 64 // was 254 before

	/*!
	 * @name napc__DNSQuery
	 * @module DNS
	 * @brief Representation of a DNS query.
	 * @version 1.0.0
	 * @field name Name to lookup.
	 * @field qtype Query type, see `napc__DNSQType`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct libnapc__DNSQuery {
		char name[NAPC_MODULE_DNS_MAX_NAME];
		libnapc__DNSQType qtype;
	} libnapc__DNSQuery;
#endif
