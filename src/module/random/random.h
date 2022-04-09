/*!
 * @name random:intro
 * @brief Random number generation
 * @description
 * This module provides random number generation suitable for cryptographic purposes.
 * 
 * A typical application looks like this:
 * 
 * ```c
 * #include <napc.h>
 * 
 * napc_u8 random_bytes[16];
 * 
 * void napc_app_setup(const char *platform) {}
 * 
 * bool napc_app_loop(napc_time uptime) {
 * 	// request of 16 random bytes
 * 	if (napc_random_getRandomBytes(16, random_bytes)) {
 * 		// do something with random_bytes
 * 
 * 		napc_printf("Here are your random numbers: ");
 * 
 * 		for (int i = 0; i < 16; ++i) {
 * 			napc_printf("%2.2x", random_bytes[i]);
 * 		}
 * 
 * 		napc_printf("\n");
 * 
 * 		return false;
 * 	}
 * 
 * 	// collect new random data
 * 	napc_random_collectBytes();
 * 
 * 	return true;
 * }
 * ```
 * 
 * This program will output something similar to:
 * 
 * ```
 * Here are your random numbers: 162109b28bba5eabb17b69d83aeffd84
 * ```
 */
#if !defined(NAPC_MODULE_RANDOM_h)
	#define NAPC_MODULE_RANDOM_h

	#include <libnapc.h>

	/*!
	 * @name napc_random_collectBytes
	 * @brief Collect random bits from various sources.
	 * @version 1.0.0
	 * @notes
	 * This function must be called periodically for `napc_random_getRandomBytes` to work.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void napc_random_collectBytes(void);

	/*!
	 * @name napc_random_getAvailableBytes
	 * @brief Get number of available random bytes.
	 * @version 1.0.0
	 * @description
	 * Get number of immediately available random bytes.
	 * @return Returns the number of available random bytes.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_size napc_random_getAvailableBytes(void) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_random_getRandomBytes
	 * @brief Create random bytes.
	 * @version 1.0.0
	 * @description
	 * Creates `n_bytes` random bytes.
	 * @param n_bytes Number of bytes to be generated.
	 * @param out Array to store collected bytes.
	 * @return Returns `true` if array `out` was filled with `n_bytes` bytes of random data.
	 * @notes
	 * `napc_random_collectBytes` must be called periodically for this function to work.
	 * @warning
	 * `out` remains UNMODIFIED if function returned `false`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u8 random_bytes[32];
	 * 
	 * if (napc_random_getRandomBytes(random_bytes, sizeof(random_bytes))) {
	 *     // random_bytes now contains 32 random bytes
	 * }
	 */
	bool napc_random_getRandomBytes(napc_size n_bytes, napc_u8 *out) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_random_getRandomBytesSync
	 * @brief Create random bytes.
	 * @version 1.5.0
	 * @description
	 * Creates `n_bytes` random bytes.
	 * @param n_bytes Number of bytes to be generated.
	 * @param out Array to store collected bytes.
	 * @warning
	 * Since this function blocks until enough random data is collected, it is better to use `napc_random_getRandomBytes`.
	 * @changelog 1.5.0 25.03.2022 initial version
	 * @example
	 * napc_u8 random_bytes[32];
	 * 
	 * napc_random_getRandomBytesSync(random_bytes, sizeof(random_bytes));
	 * 
	 * // random_bytes now contains 32 random bytes
	 */
	void napc_random_getRandomBytesSync(napc_size n_bytes, napc_u8 *out);
#endif
