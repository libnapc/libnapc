#include <module/hmac/_private/_hmac.h>

static libnapc_u8 _hmac[32]; // @static

bool libnapc_hmac_verify(
	const char *key, const libnapc_u8 *hmac,
	const void *buffer, libnapc_size buffer_size
) {
	libnapc_mzero(_hmac, sizeof(_hmac));
	libnapc_hmac_calculate(_hmac, key, buffer, buffer_size);

	return libnapc_memeql(hmac, _hmac, sizeof(_hmac));
}
