/* <-- add '!' back once ported -->
 * @name aes:intro
 * @brief Encrypt & decrypt messages
 */
#if !defined(LIBNAPC_MODULE_AES_h)
	#define LIBNAPC_MODULE_AES_h

	#include <libnapc-internal.h>

	/*!
	 * Encrypts a message with AES-256 in CBC mode.
	 * 
	 * @module aes
	 * @type fn
	 * @fullname libnapc_aes_encrypt
	 * @name encrypt
	 * @brief Encrypt a message with AES-256.
	 * @version 2.0.0
	 * @param iv Initialization vector (16 bytes)
	 * @param key Key in HEX format (32 bytes)
	 * @param buffer Buffer to encrypt.
	 * @param buffer_size Size of buffer.
	 * @warning The input buffer must always be aligned to 16 bytes.
	 * @changelog 2.0.0 initial version
	 * @example
	 * char message[32];
	 * libnapc_u8 iv[16];
	 * const char *key = "secret";
	 * char key_hashed[65];
	 * 
	 * // initialize IV with random bytes
	 * // note that napc_random_getRandomBytesSync() is used here for simplicity
	 * // it is better to use napc_random_getRandomBytes().
	 * napc_random_getRandomBytesSync(sizeof(iv), iv);
	 * 
	 * // since napc_aes_encrypt() expects a HEX formatted key string
	 * // we simply calculate the SHA256 hash of the key
	 * // which is guaranteed to be a 32 byte hex formatted string.
	 * if (napc_sha_calculate(key, napc_strlen(key), key_hashed, sizeof(key_hashed))) {
	 *     // set all bytes in message to zero
	 *     // napc_aes_encrypt() always needs the input buffer's size to be 
	 *     // a multiple of 16. This way unused bytes are always zero.
	 *     napc_mzero(message, sizeof(message));
	 * 
	 *     // copy a message
	 *     napc_strncpy(message, "Hello, World!", sizeof(message));
	 * 
	 *     // do the encryption
	 *     if (napc_aes_encrypt(iv, key_hashed, message, sizeof(message))) {
	 *         // message is now encrypted
	 *         napc_printf("Message encrypted!\n");
	 * 
	 *         napc_printf("Key: %s\n", key_hashed);
	 * 
	 *         napc_printf("IV: ");
	 *         napc_misc_printHexArray(iv, sizeof(iv));
	 *         napc_printf("\n");
	 * 
	 *         napc_printf("Ciphertext: ");
	 *         napc_misc_printHexArray(message, sizeof(message));
	 *         napc_printf("\n");
	 *     }
	 * }
	 */
	bool libnapc_aes_encrypt(
		const libnapc_u8 *iv,
		const char *key,
		void *buffer, libnapc_size buffer_size
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Decrypts a message with AES-256 in CBC mode.
	 * 
	 * @module aes
	 * @type fn
	 * @fullname libnapc_aes_decrypt
	 * @name decrypt
	 * @brief Decrypt a message with AES-256.
	 * @version 2.0.0
	 * @param iv Initialization vector (16 bytes)
	 * @param key Key in HEX format (32 bytes)
	 * @param buffer Buffer to encrypt.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning The input buffer must always be aligned to 16 bytes.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_aes_decrypt(
		const libnapc_u8 *iv,
		const char *key,
		void *buffer, libnapc_size buffer_size
	) LIBNAPC_FN_WARN_UNUSED_RET();
#endif
