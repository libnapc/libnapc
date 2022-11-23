/*!
 * @name hmac:intro
 * @brief Sign & verify messages
 */
#if !defined(NAPC_MODULE_HMAC_h)
	#define NAPC_MODULE_HMAC_h

	#include <libnapc-internal.h>

	/*!
	 * @name napc_hmac_calculate
	 * @brief Calculate HMAC of a message.
	 * @version 1.0.0
	 * @description
	 * Calculate the SHA-256 HMAC signature of a message.
	 * @param out Pointer to store resulting HMAC (32 bytes)
	 * @param key Key to be used.
	 * @param buffer Buffer containing the message.
	 * @param buffer_size Size of buffer.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void napc_hmac_calculate(
		napc_u8 *out,
		const char *key,
		const void *buffer, libnapc_size buffer_size
	);

	/*!
	 * @name napc_hmac_verify
	 * @brief Verify a message with HMAC.
	 * @version 1.0.0
	 * @description
	 * Verify a message.
	 * @param key Key to be used.
	 * @param hmac Pointer to HMAC (32 bytes)
	 * @param buffer Buffer containing the message.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` if the message matches the `hmac` signature.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_hmac_verify(
		const char *key, const napc_u8 *hmac,
		const void *buffer, libnapc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();
#endif
