#if !defined(TINYAES_H)
	#define TINYAES_H

	#include <stdint.h>
	#include <stddef.h>

	struct TinyAES_ctx {
		uint8_t RoundKey[240];
		uint8_t Iv[16];
	};

	void TinyAES_init_ctx(struct TinyAES_ctx* ctx, const uint8_t* key);

	void TinyAES_init_ctx_iv(struct TinyAES_ctx* ctx, const uint8_t* key, const uint8_t* iv);
	void TinyAES_ctx_set_iv(struct TinyAES_ctx* ctx, const uint8_t* iv);

	void TinyAES_CBC_encrypt_buffer(struct TinyAES_ctx* ctx, uint8_t* buf, size_t length);
	void TinyAES_CBC_decrypt_buffer(struct TinyAES_ctx* ctx, uint8_t* buf, size_t length);
#endif
