/** 
* libnapc
* (c) by nap.software
* 
* Reference at https://libnapc.nap-software/
* 
* Version    : %BC_RELEASE_VERSION%
* Git commit : %BC_GIT_HEAD_HASH%
*/
#if !defined(NAPC_h)
	#define NAPC_h

	#if defined(__cplusplus)
		extern "C" {
	#endif

	/*!
	 * @name napc_version
	 * @brief Get the version of libnapc.
	 * @version 1.2.0
	 * @description
	 * Return the version string of libnapc.
	 * @changelog 1.2.0 20.03.2022 initial version
	 * @example
	 * napc_printf("Using libnapc version: %s\n", napc_version());
	 */
	const char *napc_version(void);

	/*!
	 * @name napc_getFullVersion
	 * @brief Get the full version of libnapc.
	 * @version 1.3.0
	 * @description
	 * Return the full version string of libnapc.
	 * @changelog 1.3.0 21.03.2022 initial version
	 * @example
	 * napc_printf("Using libnapc version: %s\n", napc_getFullVersion());
	 */
	const char *napc_getFullVersion(void);

	#include <napc-serial/napc-serial.h>
	#include <napc-time/napc-time.h>
	#include <napc-delay/napc-delay.h>
	#include <napc-utils/napc-utils.h>
	#include <napc-panic/napc-panic.h>
	#include <napc-core/napc-core.h>
	#include <napc-log/napc-log.h>
	#include <napc-rand-source/napc-rand-source.h>

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

	extern void napc_main(const char *platform);

	#if defined(__cplusplus)
		}
	#endif
#endif
