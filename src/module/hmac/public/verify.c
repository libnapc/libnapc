#include <module/hmac/_private/_hmac.h>

static napc_u8 _hmac[32]; // @static

bool napc_hmac_verify(
	const char *key, const napc_u8 *hmac,
	const void *buffer, napc_size buffer_size
) {
	napc_mzero(_hmac, sizeof(_hmac));
	napc_hmac_calculate(_hmac, key, buffer, buffer_size);

	return napc_memeql(hmac, _hmac, sizeof(_hmac));
}
