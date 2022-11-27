#include <module/aes/_private/_aes.h>

bool napc_aes_encrypt(
	const libnapc_u8 *iv,
	const char *key,
	void *buffer, libnapc_size buffer_size
) {
	struct TinyAES_ctx ctx;
	libnapc_u8 key_bytes[32];

	if ((buffer_size % 16) != 0) {
		LIBNAPC_PANIC("buffer size must be a multiple of 16 bytes.");
	}

	if (
		!libnapc_parser_parseHexString(key, sizeof(key_bytes), key_bytes)
	) {
		libnapc_mzero(key_bytes, sizeof(key_bytes));

		return false;
	}

	TinyAES_init_ctx_iv(&ctx, key_bytes, iv);

	TinyAES_CBC_encrypt_buffer(&ctx, buffer, buffer_size);
	libnapc_mzero(key_bytes, sizeof(key_bytes));
	libnapc_mzero(&ctx, sizeof(ctx));

	return true;
}
