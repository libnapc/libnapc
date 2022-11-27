#if !defined(LIBNAPC_HAL_h)
	#define LIBNAPC_HAL_h

	#include <libnapc-internal.h>
	#include <libnapc-target.h>

	#if defined(__cplusplus)
		extern "C" {
	#endif

	// libnapc-time
		void HAL_libnapc_initTime(void);
		libnapc_time HAL_libnapc_getTimeSinceBoot(bool high_res);
	// libnapc-time

	// libnapc-serial
		void HAL_libnapc_initSerial(void);
		void HAL_libnapc_puts(const char *str);
		void HAL_libnapc_putc(char ch);
	// libnapc-serial

	// libnapc-panic
		void HAL_libnapc_abort(void) LIBNAPC_FN_NORETURN();
	// libnapc-panic

	// libnapc-delay
		void HAL_libnapc_delay(libnapc_time amount);
		void HAL_libnapc_delayUs(libnapc_time amount);
	// libnapc-delay

	// libnapc-log
		void HAL_libnapc_determineColorOutput(void);
	// libnapc-log

	// libnapc-core
		libnapc_size HAL_libnapc_getFreeMemory(void) LIBNAPC_FN_WARN_UNUSED_RET();
	// libnapc-core

	#if defined(__cplusplus)
		}
	#endif
#endif
