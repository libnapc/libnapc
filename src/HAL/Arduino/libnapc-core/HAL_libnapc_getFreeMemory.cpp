#include <HAL/HAL.h>

#if defined(LIBNAPC_TARGET) && LIBNAPC_TARGET == LIBNAPC_TARGET_ARDUINO_GENERIC
	extern "C" {
		#include <libnapc-core/_private/_libnapc-core.h>

		#ifdef __arm__
			// should use uinstd.h to define sbrk but Due causes a conflict
			extern "C" char* sbrk(int incr);
		#else  // __ARM__
			extern char *__brkval;
		#endif  // __arm__

		libnapc_size HAL_libnapc_getFreeMemory(void) {
			char top;
			#ifdef __arm__
				return &top - reinterpret_cast<char*>(sbrk(0));
			#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
				return &top - __brkval;
			#else  // __arm__
				return __brkval ? &top - __brkval : &top - __malloc_heap_start;
			#endif  // __arm__
		}
	}
#endif
