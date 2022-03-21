#if !defined(NAPC_MODULE_DNS_ANSWER_h)
	#define NAPC_MODULE_DNS_ANSWER_h

	#include <libnapc.h>

	/*!
	 * @name napc__DNSAnswer
	 * @brief Representation of a DNS answer.
	 * @version 1.0.0
	 * @field ttl Time to live (in seconds).
	 * @field rd_length Response data size in bytes.
	 * @field rd_data Response data.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct {
		napc_u32 ttl;

		napc_u16 rd_length;
		napc_u8 rd_data[16];
	} napc__DNSAnswer;
#endif
