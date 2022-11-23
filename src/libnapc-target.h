#if !defined(LIBNAPC_TARGET_h)
	#define LIBNAPC_TARGET_h

	#define LIBNAPC_TARGET_LINUX_GENERIC   0
	#define LIBNAPC_TARGET_ARDUINO_GENERIC 1

	#if !defined(LIBNAPC_TARGET)
		#if defined(ARDUINO)
			#define LIBNAPC_TARGET LIBNAPC_TARGET_ARDUINO_GENERIC
		#else
			#define LIBNAPC_TARGET LIBNAPC_TARGET_LINUX_GENERIC
		#endif
	#endif
#endif
