#if !defined(LIBNAPC_HAL_h)
	#define LIBNAPC_HAL_h

	#include <libnapc-internal.h>
	#include <libnapc-target.h>

	#if defined(__cplusplus)
		extern "C" {
	#endif

	// napc-time
		void HAL_libnapc_initTime(void);
		libnapc_time HAL_libnapc_getTimeSinceBoot(bool high_res);
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
		void HAL_libnapc_delay(libnapc_time amount);
		void HAL_libnapc_delayUs(libnapc_time amount);
	// napc-delay

	// napc-core
		libnapc_size HAL_libnapc_getFreeMemory(void) NAPC_FN_WARNUNUSED_RET();
	// napc-core

	#if defined(__cplusplus)
		}
	#endif
#endif
