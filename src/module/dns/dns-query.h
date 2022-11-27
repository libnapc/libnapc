#if !defined(LIBNAPC_MODULE_DNS_QUERY_h)
	#define LIBNAPC_MODULE_DNS_QUERY_h

	#include <libnapc-internal.h>
	#include <module/dns/dns-qtype.h>

	#define LIBNAPC_MODULE_DNS_MAX_NAME 64 // was 254 before

	/*!
	 * @module DNS
	 * @type type:struct
	 * @fullname libnapc__DNSQuery
	 * @brief Representation of a DNS query.
	 * @version 2.0.0
	 * @field name Name to lookup.
	 * @field qtype Query type, see `libnapc__DNSQType`.
	 * @changelog 2.0.0 initial version
	 */
	typedef struct libnapc__DNSQuery {
		char name[LIBNAPC_MODULE_DNS_MAX_NAME];
		libnapc__DNSQType qtype;
	} libnapc__DNSQuery;
#endif
