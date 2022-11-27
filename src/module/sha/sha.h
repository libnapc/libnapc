#if !defined(LIBNAPC_MODULE_SHA_h)
	#define LIBNAPC_MODULE_SHA_h

	#include <libnapc-internal.h>

	/*!
	 * Calculates the SHA-256 hash of a message.
	 * 
	 * @module sha
	 * @type fn
	 * @fullname libnapc_sha_calculate
	 * @name calculate
	 * @brief Calculate SHA256 hash.
	 * @version 2.0.0
	 * @param buffer Buffer to calculate hash of.
	 * @param buffer_size Size of buffer.
	 * @param out Array to store output in HEX format (32 bytes).
	 * @param out_size Size of output array.
	 * @warning The output array must have at least 65 elements.
	 * @changelog 2.0.0 initial version
	 * @example
	 * char out[65];
	 * const char *str = "secret";
	 * 
	 * libnapc_sha_calculate(str, libnapc_strlen(str), out, sizeof(out));
	 * 
	 * libnapc_printf("SHA256-hash of '%s' is '%s'\n");
	 */
	bool libnapc_sha_calculate(
		const void *buffer, libnapc_size buffer_size,
		char *out, libnapc_size out_size
	) LIBNAPC_FN_WARN_UNUSED_RET();
#endif
