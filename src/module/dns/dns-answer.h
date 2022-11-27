#if !defined(LIBNAPC_MODULE_DNS_ANSWER_h)
	#define LIBNAPC_MODULE_DNS_ANSWER_h

	#include <libnapc-internal.h>

	#define NAPC_MODULE_DNS_MAX_RD_DATA_LENGTH 16u

	/*!
	 * @module DNS
	 * @type type:struct
	 * @fullname libnapc__DNSAnswer
	 * @brief Representation of a DNS answer.
	 * @version 2.0.0
	 * @field ttl Time to live (in seconds).
	 * @field rd_length Response data size in bytes.
	 * @field rd_data Response data.
	 * @changelog 2.0.0 initial version
	 */
	typedef struct libnapc__DNSAnswer {
		libnapc_u32 ttl;

		libnapc_u16 rd_length;
		libnapc_u8 rd_data[NAPC_MODULE_DNS_MAX_RD_DATA_LENGTH];
	} libnapc__DNSAnswer;
#endif
