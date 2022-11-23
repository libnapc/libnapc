#if !defined(LIBNAPC_HAL_h)
	#define LIBNAPC_HAL_h

	#include <libnapc-internal.h>
	#include <libnapc-target.h>

	#if defined(__cplusplus)
		extern "C" {
	#endif

	// napc-time
		void HAL_libnapc_initTime(void);
		napc_time HAL_libnapc_getTimeSinceBoot(bool high_res);
	// napc-time

	// napc-serial
		void HAL_libnapc_initSerial(void);
		void HAL_libnapc_puts(const char *str);
		void HAL_libnapc_putc(char ch);
	// napc-serial

	// napc-panic
		void HAL_napc_abort(void) NAPC_FN_NORETURN();
	// napc-panic

	// napc-delay
		void HAL_napc_delay(napc_time amount);
		void HAL_napc_delayUs(napc_time amount);
	// napc-delay

	// napc-core
		napc_size HAL_napc_getFreeMemory(void) NAPC_FN_WARNUNUSED_RET();
	// napc-core

	#if defined(__cplusplus)
		}
	#endif
#endif
