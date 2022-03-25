#if !defined(NAPC_MODULE_AES_h)
	#define NAPC_MODULE_AES_h

	#include <libnapc.h>

	/*!
	 * @name napc_aes_encrypt
	 * @brief Encrypt a message with AES-256.
	 * @version 1.0.0
	 * @description
	 * Encrypt a message with AES-256 in CBC mode.
	 * @param iv Initialization vector (16 bytes)
	 * @param key Key in HEX format (32 bytes)
	 * @param buffer Buffer to encrypt.
	 * @param buffer_size Size of buffer.
	 * @warning The input buffer must always be aligned to 16 bytes.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char message[32];
	 * napc_u8 iv[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	 * const char *key = "secret";
	 * char key_hashed[65];
	 * 
	 * if (napc_sha_calculate(key, napc_strlen(key), key_hashed, sizeof(key_hashed))) {
	 *     napc_mzero(message, sizeof(message));
	 * 
	 *     napc_strncpy(message, "Hello, World!", sizeof(message));
	 * 
	 *     if (napc_aes_encrypt(iv, key_hashed, message, sizeof(message))) {
	 *         // message is now encrypted
	 *     }
	 * }
	 */
	bool napc_aes_encrypt(
		const napc_u8 *iv,
		const char *key,
		void *buffer, napc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_aes_decrypt
	 * @brief Decrypt a message with AES-256.
	 * @version 1.0.0
	 * @description
	 * Decrypt a message with AES-256 in CBC mode.
	 * @param iv Initialization vector (16 bytes)
	 * @param key Key in HEX format (32 bytes)
	 * @param buffer Buffer to encrypt.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning The input buffer must always be aligned to 16 bytes.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_aes_decrypt(
		const napc_u8 *iv,
		const char *key,
		void *buffer, napc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();
#endif
