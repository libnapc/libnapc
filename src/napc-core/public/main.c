#include <napc-core/_private/_napc-core.h>

const char *napc_getFullVersion(void);

napc_time PV_napc_uptime = 0; // @global

void napc_main(const char *platform) {
	napc_time reference = napc_getTimeSinceBoot();

	napc_printf("(c) by nap.software (platform=%s)\n", platform);
	napc_printf("Using libnapc version %s\n", napc_getFullVersion());

	napc_setup(platform);

	while (true) {
		napc_time delta = napc_getTimeSinceBoot() - reference;

		if (!napc_loop(PV_napc_uptime)) break;

		// 1000ms is 1s
		if (delta >= NAPC_TIME_LITERAL(1000)) {
			napc_time n_seconds = (delta / NAPC_TIME_LITERAL(1000));
			PV_napc_uptime += n_seconds;

			reference = napc_getTimeSinceBoot();
		}

		// prevent high cpu usage on linux systems
		HAL_napc_loopYieldCPU(false);
	}
}
