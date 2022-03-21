#if !defined(NAPC_MODULE_DNS_HEADER_h)
	#define NAPC_MODULE_DNS_HEADER_h

	#include <libnapc.h>

	/*!
	 * @name napc__DNSOPCode
	 * @brief Representation of a DNS operation code.
	 * @version 1.0.0
	 * @enum NAPC_DNS_OPCODE_QUERY Standard DNS-Query.
	 * @enum NAPC_DNS_OPCODE_IQUERY Inverse DNS-Query.
	 * @enum NAPC_DNS_OPCODE_STATUS Status op.
	 * @enum NAPC_DNS_OPCODE_NOTIFY
	 * @enum NAPC_DNS_OPCODE_UPDATE
	 */
	typedef enum {
		NAPC_DNS_OPCODE_QUERY,
		NAPC_DNS_OPCODE_IQUERY,
		NAPC_DNS_OPCODE_STATUS,
		NAPC_DNS_OPCODE_NOTIFY,
		NAPC_DNS_OPCODE_UPDATE
	} napc__DNSOPCode;

	/*!
	 * @name napc__DNSHeader
	 * @brief Representation of a DNS header.
	 * @version 1.0.0
	 * @field opcode DNS operation code. See `napc__DNSOPCode`.
	 * @field authoritative_answer Authoritative answer flag.
	 * @field truncated Truncated flag.
	 * @field request_identifier DNS request identifier.
	 * @field response_code DNS-Server response code.
	 * @field question_count Number of DNS queries.
	 * @field answer_count Number of DNS answers.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct {
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
		const void *buffer, napc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();
#endif
