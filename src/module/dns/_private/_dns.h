#if !defined(PV_NAPC_MODULE_DNS_h)
	#define PV_NAPC_MODULE_DNS_h

	#include <module/dns/dns.h>
	#include <module/dns/_private/_log.h>

	#include <module/reader/reader.h>
	#include <module/writer/writer.h>
	#include <libnapc-utils/libnapc-utils.h> // libnapc_strncpy()
	#include <string.h> // memcpy()

	/**
	 * This code was taken from https://elixir.bootlin.com/musl/v1.2.2/source/src/network/dn_expand.c
	 * It's responsible for expanding compressed dns names.
	 */
	int PV_napc_DNS_dn_expand(
		// pointer to start of message
		const unsigned char *base,
		// pointer to end of message
		const unsigned char *end,
		// pointer to compressed name
		const unsigned char *src,
		// buffer for name
		char *dest,
		int space
	) LIBNAPC_FN_WARN_UNUSED_RET();

	bool PV_napc_DNS_parseQuerySection(
		napc__DNSQuery *out,
		napc__Reader *reader
	) LIBNAPC_FN_WARN_UNUSED_RET();

	bool PV_napc_DNS_parseAnswerSection(
		napc__DNSAnswer *out,
		napc__Reader *reader
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/**
	 * Used as a temporary buffer when expanding
	 * compressed dns names.
	 */
	extern char PV_napc_DNS_tmp_name[NAPC_MODULE_DNS_MAX_NAME]; // @global


#endif
