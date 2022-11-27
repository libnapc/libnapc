/* <-- add '!' back once ported -->
 * @name hmac:intro
 * @brief Sign & verify messages
 */
#if !defined(LIBNAPC_MODULE_HMAC_h)
	#define LIBNAPC_MODULE_HMAC_h

	#include <libnapc-internal.h>

	/*!
	 * Calculates the SHA-256 HMAC signature of a message.
	 * 
	 * @module hmac
	 * @type fn
	 * @fullname libnapc_hmac_calculate
	 * @name calculate
	 * @brief Calculate HMAC of a message.
	 * @version 2.0.0
	 * @param out Pointer to store resulting HMAC (32 bytes)
	 * @param key Key to be used.
	 * @param buffer Buffer containing the message.
	 * @param buffer_size Size of buffer.
	 * @changelog 2.0.0 initial version
	 */
	void libnapc_hmac_calculate(
		libnapc_u8 *out,
		const char *key,
		const void *buffer, libnapc_size buffer_size
	);

	/*!
	 * Verifies a message.
	 * 
	 * @module hmac
	 * @type fn
	 * @fullname libnapc_hmac_verify
	 * @name verify
	 * @brief Verify a message with HMAC.
	 * @version 2.0.0
	 * @param key Key to be used.
	 * @param hmac Pointer to HMAC (32 bytes)
	 * @param buffer Buffer containing the message.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` if the message matches the `hmac` signature.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_hmac_verify(
		const char *key, const libnapc_u8 *hmac,
		const void *buffer, libnapc_size buffer_size
	) LIBNAPC_FN_WARN_UNUSED_RET();
#endif
