#if !defined(LIBNAPC_MODULE_DNS_HEADER_h)
	#define LIBNAPC_MODULE_DNS_HEADER_h

	#include <libnapc-internal.h>

	/*!
	 * @module DNS
	 * @type type:enum
	 * @fullname libnapc__DNSOPCode
	 * @brief Representation of a DNS operation code.
	 * @version 2.0.0
	 * @enum LIBNAPC_DNS_OPCODE_QUERY Standard DNS-Query.
	 * @enum LIBNAPC_DNS_OPCODE_IQUERY Inverse DNS-Query.
	 * @enum LIBNAPC_DNS_OPCODE_STATUS Status query.
	 * @enum LIBNAPC_DNS_OPCODE_NOTIFY tbd
	 * @enum LIBNAPC_DNS_OPCODE_UPDATE tbd
	 * @changelog 2.0.0 initial version
	 */
	typedef enum libnapc__DNSOPCode {
		LIBNAPC_DNS_OPCODE_QUERY,
		LIBNAPC_DNS_OPCODE_IQUERY,
		LIBNAPC_DNS_OPCODE_STATUS,
		LIBNAPC_DNS_OPCODE_NOTIFY,
		LIBNAPC_DNS_OPCODE_UPDATE
	} libnapc__DNSOPCode;

	/*!
	 * @module DNS
	 * @type type:struct
	 * @fullname libnapc__DNSHeader
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
	 * @changelog 2.0.0 initial version
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
	 * @module DNS
	 * @type fn
	 * @fullname libnapc_DNS_parseHeader
	 * @name parseHeader
	 * @brief Parse a DNS-Header from a buffer.
	 * @version 2.0.0
	 * @param out Pointer to a `napc__DNSHeader` to store result.
	 * @param buffer Buffer to be parsed.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_DNS_parseHeader(
		libnapc__DNSHeader *out,
		const void *buffer, libnapc_size buffer_size
	) LIBNAPC_FN_WARN_UNUSED_RET();
#endif
