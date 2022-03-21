#if !defined(NAPC_MODULE_DNS_QUERY_h)
	#define NAPC_MODULE_DNS_QUERY_h

	#include <libnapc.h>
	#include <module/dns/dns-qtype.h>

	#define NAPC_MODULE_DNS_MAX_NAME 254u

	/*!
	 * @name napc__DNSQuery
	 * @brief Representation of a DNS query.
	 * @version 1.0.0
	 * @field name Name to lookup.
	 * @field qtype Query type, see `napc__DNSQType`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct {
		char name[NAPC_MODULE_DNS_MAX_NAME];
		napc__DNSQType qtype;
	} napc__DNSQuery;
#endif
