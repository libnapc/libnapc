#include <module/hmac/_private/_hmac.h>

void libnapc_hmac_calculate(
	libnapc_u8 *out,
	const char *key,
	const void *buffer, libnapc_size buffer_size
) {
	H5P9SL_hmac_sha256(
		// key, keylen
		key, libnapc_strlen(key),
		// data, datalen
		buffer, buffer_size,
		// out, outlen
		out, 32
	);
}
