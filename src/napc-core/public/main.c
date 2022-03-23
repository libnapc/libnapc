#include <napc-core/_private/_napc-core.h>

const char *napc_version(void);

napc_time PV_napc_uptime = 0; // @global

void napc_main(const char *platform) {
	napc_time reference = napc_getTimeSinceBoot();

	napc_printf("(c) by nap.software (platform=%s)\n", platform);
	napc_printf("Using libnapc version %s\n", napc_version());

	#if defined(LIBNAPC_GIT_BRANCH)
		if (!napc_streqli(LIBNAPC_GIT_BRANCH, "main")) {
			napc_printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			napc_printf(
				"! warning: not using a stable software release of libnapc !\n"
			);
			napc_printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
		}
	#endif

	napc_setup(platform);

	bool is_linux = napc_streqli(platform, "linux");

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
		if (is_linux) {
			napc_delay(5);
		}
	}
}
