#if !defined(LIBNAPC_MODULE_DNS_HEADER_h)
	#define LIBNAPC_MODULE_DNS_HEADER_h

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
	typedef enum libnapc__DNSOPCode {
		NAPC_DNS_OPCODE_QUERY,
		NAPC_DNS_OPCODE_IQUERY,
		NAPC_DNS_OPCODE_STATUS,
		NAPC_DNS_OPCODE_NOTIFY,
		NAPC_DNS_OPCODE_UPDATE
	} libnapc__DNSOPCode;

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
	typedef struct libnapc__DNSHeader {
		libnapc_u16 raw_flags;

		libnapc__DNSOPCode opcode;

		bool authoritative_answer;
		bool truncated;
//		bool recursion_desired;
//		bool recursion_available;

		libnapc_u16 request_identifier;
		libnapc_u16 response_code;
		libnapc_u16 question_count;
		libnapc_u16 answer_count;
	} libnapc__DNSHeader;

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
	bool libnapc_DNS_parseHeader(
		libnapc__DNSHeader *out,
		const void *buffer, libnapc_size buffer_size
	) LIBNAPC_FN_WARN_UNUSED_RET();
#endif
