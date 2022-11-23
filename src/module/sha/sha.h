#if !defined(NAPC_MODULE_SHA_h)
	#define NAPC_MODULE_SHA_h

	#include <libnapc-internal.h>

	/*!
	 * @name napc_sha_calculate
	 * @brief Calculate SHA256 hash.
	 * @version 1.5.0
	 * @description
	 * Calculates the SHA-256 hash of a message.
	 * @param buffer Buffer to calculate hash of.
	 * @param buffer_size Size of buffer.
	 * @param out Array to store output in HEX format (32 bytes).
	 * @param out_size Size of output array.
	 * @warning The output array must have at least 65 elements.
	 * @changelog 1.5.0 25.03.2022 initial version
	 * @example
	 * char out[65];
	 * const char *str = "secret";
	 * 
	 * napc_sha_calculate(str, napc_strlen(str), out, sizeof(out));
	 * 
	 * napc_printf("SHA256-hash of '%s' is '%s'\n");
	 */
	bool napc_sha_calculate(
		const void *buffer, napc_size buffer_size,
		char *out, napc_size out_size
	) NAPC_FN_WARNUNUSED_RET();
#endif
