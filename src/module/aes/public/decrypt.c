#include <module/aes/_private/_aes.h>

bool napc_aes_decrypt(
	const napc_u8 *iv,
	const char *key,
	void *buffer, napc_size buffer_size
) {
	struct TinyAES_ctx ctx;
	napc_u8 key_bytes[32];

	if ((buffer_size % 16) != 0) {
		NAPC_PANIC("buffer size must be a multiple of 16 bytes.");
	}

	if (
		!napc_parser_parseHexString(key, sizeof(key_bytes), key_bytes)
	) {
		napc_mzero(key_bytes, sizeof(key_bytes));

		return false;
	}

	TinyAES_init_ctx_iv(&ctx, key_bytes, iv);

	TinyAES_CBC_decrypt_buffer(&ctx, buffer, buffer_size);
	napc_mzero(key_bytes, sizeof(key_bytes));
	napc_mzero(&ctx, sizeof(ctx));

	return true;
}
