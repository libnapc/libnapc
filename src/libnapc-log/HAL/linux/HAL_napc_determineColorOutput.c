#if !defined(ARDUINO)
	#include <libnapc-log/_private/_libnapc-log.h>
	#include <libnapc-serial/libnapc-serial.h> // napc_printf()
	#include <string.h> // strlen(), strcasecmp()

	void HAL_napc_determineColorOutput(void) {
		const char *colorful_output= getenv("NAPC_COLORFUL_OUTPUT");

		if (!colorful_output) return;

		PV_libnapc_log_colorful_output = strcasecmp(colorful_output, "yes") == 0;

		if (PV_libnapc_log_colorful_output) {
			libnapc_printf("HAL_napc_determineColorOutput (linux) using colorful output.");
		}
	}
#endif
