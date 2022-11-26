/** 
* libnapc
* (c) by nap.software
* 
* Reference at https://libnapc.nap-software/
* 
* Version    : %BC_RELEASE_VERSION%
* Git commit : %BC_GIT_HEAD_HASH%
*/
#if !defined(LIBNAPC_h)
	#define LIBNAPC_h

	#if defined(__cplusplus)
		extern "C" {
	#endif

	/*!
	 * Initialises libnapc.
	 * 
	 * Call this function before calling any other function of libnapc.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname libnapc_init
	 * @brief Initialise libnapc.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @warning
	 * This function must be called before using any of the library functions.
	 */
	void libnapc_init(void);

	/*!
	 * Return the version string of libnapc.
	 * 
	 * @module Core
	 * @fullname libnapc_version
	 * @type fn
	 * @brief Get the version of libnapc.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * napc_printf("Using libnapc version: %s\n", libnapc_version());
	 */
	const char *libnapc_version(void);

	/*!
	 * Return the full version string of libnapc.
	 * 
	 * @module Core
	 * @fullname libnapc_getFullVersion
	 * @type fn
	 * @brief Get the full version of libnapc.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * napc_printf("Using libnapc version: %s\n", libnapc_getFullVersion());
	 */
	const char *libnapc_getFullVersion(void);

	#include <napc-serial/napc-serial.h>
	#include <napc-time/napc-time.h>
	#include <napc-delay/napc-delay.h>
	#include <napc-utils/napc-utils.h>
	#include <napc-panic/napc-panic.h>
	#include <napc-core/napc-core.h>
	#include <napc-log/napc-log.h>

	#include <module/pool/pool.h>
	#include <module/hr-timer/hr-timer.h>
	#include <module/timer/timer.h>
	#include <module/parser/parser.h>
	#include <module/aes/aes.h>
	#include <module/hmac/hmac.h>
	#include <module/misc/misc.h>
	#include <module/reader/reader.h>
	#include <module/writer/writer.h>
	#include <module/ipv4participant/ipv4participant.h>
	#include <module/dns/dns.h>
	#include <module/sha/sha.h>
	#include <module/ring-buffer/ring-buffer.h>

	#if defined(__cplusplus)
		}
	#endif
#endif
