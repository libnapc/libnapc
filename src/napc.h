/** 
* libnapc
* (c) by nap.software
* 
* Reference at https://libnapc.nap-software/
* 
* Version    : %BC_RELEASE_VERSION%
* Git branch : %BC_GIT_BRANCH%
* Git head   : %BC_GIT_HEAD_HASH%
* Build date : %BC_BUILD_DATE%
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
	 * Returns the version of the current libnapc implementation.
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
	 * Returns the full version of the current libnapc implementation.
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
	#include <module/timer/timer.h>
	#include <module/random/random.h>
	#include <module/parser/parser.h>
	#include <module/aes/aes.h>
	#include <module/hmac/hmac.h>
	#include <module/misc/misc.h>
	#include <module/reader/reader.h>
	#include <module/writer/writer.h>
	#include <module/ipv4participant/ipv4participant.h>
	#include <module/dns/dns.h>
	#include <module/mem/mem.h>
	#include <module/sha/sha.h>

	#include <hw.module/eth/eth.h>
	#include <hw.module/udp/udp.h>
	#include <hw.module/file/file.h>
	#include <hw.module/fs/fs.h>
	#include <hw.module/env/env.h>

	#include <module/app/app.h>

	extern void napc_main(const char *platform);

	#if defined(__cplusplus)
		}
	#endif
#endif
