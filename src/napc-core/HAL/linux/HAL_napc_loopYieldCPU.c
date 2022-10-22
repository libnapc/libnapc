#if !defined(ARDUINO)
	#include <napc-core/_private/_napc-core.h>
	#include <napc-serial/napc-serial.h> // napc_printf()

	#include <stdio.h> // sscanf()
	#include <string.h> // strlen()
	#include <stdlib.h>

	static napc_time current_delay = 0;

	static napc_time getLoopDelay(void) {
		// it's likely that the current_delay has already been calculated
		if (NAPC_LIKELY(current_delay > 0)) {
			return current_delay;
		}

		napc_time delay_value_in_us = 5000; // 5000us is 5ms
		napc_time delay_multiplier = 1;
		unsigned mult = 1;

		const char *delay_value = getenv("NAPC_LOOP_DELAY");

		if (delay_value && strlen(delay_value) >= 1) {
			const char suffix = delay_value[strlen(delay_value) - 1];

			// m = milliseconds
			if (suffix == 'm') {
				mult = 1000;
			}
			// u = microseconds
			else if (suffix == 'u') {
				mult = 1;
			}
			// warn on suffix that is not 0-9
			else if (suffix > '9' || '0' > suffix) {
				napc_printf("[warn] HAL_napc_loopYieldCPU: invalid suffix '%c'\n", suffix);
			}

			unsigned val = 0;

			if (sscanf(delay_value, "%u", &val) == 1) {
				// only take multiplier when val is correct
				if (val != 0) {
					delay_value_in_us = (napc_time)val;
					delay_multiplier = (napc_time)mult;
				} else {
					napc_printf(
						"[warn] HAL_napc_loopYieldCPU: delay cannot be zero.\n"
					);
				}
			} else {
				napc_printf(
					"[warn] HAL_napc_loopYieldCPU: failed to parse 'NAPC_LOOP_DELAY'='%s'\n",
					delay_value
				);
			}
		}

		current_delay = delay_value_in_us * delay_multiplier;

		napc_printf("[info] HAL_napc_loopYieldCPU: using delay of %u microseconds\n", current_delay);

		return current_delay;
	}

	void HAL_napc_loopYieldCPU(void) {
		napc_time delay_value_in_us = getLoopDelay();

		napc_delayUs(delay_value_in_us);
	}
#endif
