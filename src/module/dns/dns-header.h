#if !defined(NAPC_MODULE_DNS_HEADER_h)
	#define NAPC_MODULE_DNS_HEADER_h

	#include <libnapc-internal.h>

	/*!
	 * @name napc__DNSOPCode
	 * @module DNS
	 * @brief Representation of a DNS operation code.
	 * @version 1.0.0
	 * @enum NAPC_DNS_OPCODE_QUERY Standard DNS-Query.
	 * @enum NAPC_DNS_OPCODE_IQUERY Inverse DNS-Query.
	 * @enum NAPC_DNS_OPCODE_STATUS Status query.
	 * @enum NAPC_DNS_OPCODE_NOTIFY
	 * @enum NAPC_DNS_OPCODE_UPDATE
	 */
	typedef enum napc__DNSOPCode {
		NAPC_DNS_OPCODE_QUERY,
		NAPC_DNS_OPCODE_IQUERY,
		NAPC_DNS_OPCODE_STATUS,
		NAPC_DNS_OPCODE_NOTIFY,
		NAPC_DNS_OPCODE_UPDATE
	} napc__DNSOPCode;

	/*!
	 * @name napc__DNSHeader
	 * @module DNS
	 * @brief Representation of a DNS header.
	 * @version 2.0.0
	 * @field raw_flags Contains the raw dns header flags (16 bit)
	 * @field opcode DNS operation code. See `napc__DNSOPCode`.
	 * @field authoritative_answer Authoritative answer flag.
	 * @field truncated Truncated flag.
	 * @field request_identifier DNS request identifier.
	 * @field response_code DNS-Server response code.
	 * @field question_count Number of DNS queries.
	 * @field answer_count Number of DNS answers.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @changelog 2.0.0 12.04.2022 added `raw_flags` member
	 */
	typedef struct napc__DNSHeader {
		napc_u16 raw_flags;

		napc__DNSOPCode opcode;

		bool authoritative_answer;
		bool truncated;
//		bool recursion_desired;
//		bool recursion_available;

		napc_u16 request_identifier;
		napc_u16 response_code;
		napc_u16 question_count;
		napc_u16 answer_count;
	} napc__DNSHeader;

	/*!
	 * @name napc_DNS_parseHeader
	 * @brief Parse a DNS-Header from a buffer.
	 * @version 1.0.0
	 * @param out Pointer to a `napc__DNSHeader` to store result.
	 * @param buffer Buffer to be parsed.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_DNS_parseHeader(
		napc__DNSHeader *out,
		const void *buffer, libnapc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();
#endif
