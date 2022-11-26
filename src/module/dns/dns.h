#if !defined(LIBNAPC_MODULE_DNS_h)
	#define LIBNAPC_MODULE_DNS_h

	#include <libnapc-internal.h>
	#include <module/dns/dns-header.h>
	#include <module/dns/dns-query.h>
	#include <module/dns/dns-answer.h>

	#include <module/reader/reader.h>

	#define NAPC_MODULE_DNS_MAX_ANSWERS 4u

	/*!
	 * @name napc__DNSRequest
	 * @module DNS
	 * @brief Representation of a DNS request.
	 * @version 1.0.0
	 * @field header DNS-Header, see `napc__DNSHeader`.
	 * @field query DNS-Query, see `napc__DNSQuery`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct napc__DNSRequest {
		napc__DNSHeader header;
		napc__DNSQuery query;
	} napc__DNSRequest;

	/*!
	 * @name napc__DNSResponse
	 * @module DNS
	 * @brief Representation of a DNS response.
	 * @version 1.0.0
	 * @field header DNS-Header, see `napc__DNSHeader`.
	 * @field num_answers Represents number of elements in `answers` array.
	 * @field answers DNS-Answers, see `napc__DNSAnswer`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct napc__DNSResponse {
		napc__DNSHeader header;
		// this field is different from header.answer_count
		// header.answer_count contains the raw count of the number of
		// answers present in the response.
		// num_answers says how many elements are in the answers[] array
		// (might be capped)
		libnapc_size num_answers;
		napc__DNSAnswer answers[NAPC_MODULE_DNS_MAX_ANSWERS];
	} napc__DNSResponse;

	/*!
	 * @name napc_DNS_parseRequest
	 * @brief Parse a DNS-Request from a buffer.
	 * @version 1.0.0
	 * @param out Pointer to a `napc__DNSRequest` to store result.
	 * @param buffer Buffer to be parsed.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_DNS_parseRequest(
		napc__DNSRequest *out,
		const void *buffer, libnapc_size buffer_size
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * @name napc_DNS_parseResponse
	 * @brief Parse a DNS-Response from a buffer.
	 * @version 1.0.0
	 * @description
	 * Parse a DNS-Response from a buffer.
	 * @param out Pointer to a `napc__DNSResponse` to store result.
	 * @param buffer Buffer to be parsed.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_DNS_parseResponse(
		napc__DNSResponse *out,
		const void *buffer, libnapc_size buffer_size
	) LIBNAPC_FN_WARN_UNUSED_RET();
	// idea: to support more than 4 dns answers:
	// add *answers_out pointer for dynamic sizing of expected
	// answers:
		// napc__DNSAnswer answers[8];
#endif
