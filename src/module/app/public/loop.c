#include <module/app/_private/_app.h>

static bool _previous_link_status = false; // @static

bool napc_app_loop(napc_time uptime) NAPC_FN_WEAK();
bool napc_loop(napc_time uptime) NAPC_FN_WEAK();

bool napc_app_loop(napc_time uptime) {
	NAPC_IGNORE_VALUE(uptime);

	napc_printf("warning: napc_app_loop() is not defined.\n");

	return false;
}

bool napc_loop(napc_time uptime) {
	bool link_status = napc_eth_getLinkStatus();

	napc_random_collectBytes();

	if (link_status && !_previous_link_status) {
		PV_NAPC_APP_INFO("Ethernet is up.");
	}

	bool cont = napc_app_loop(uptime);

	/**
	 * Give application the chance to close all network sockets.
	 */
	if (!link_status && _previous_link_status) {
		PV_NAPC_APP_INFO("Ethernet is down.");

		napc_size open_sockets = napc_UDP_getNumOpenSockets();

		if (open_sockets) {
			NAPC_PANIC(
				"Ethernet is down but some UDP sockets (count=%" NAPC_SIZE_PRINTF ") are still open.",
				open_sockets
			);
		}
	}

	_previous_link_status = link_status;

	return cont;
}
