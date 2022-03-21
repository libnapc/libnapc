#include <napc-core/_private/_napc-core.h>

extern napc_time PV_napc_uptime; // @global

napc_time napc_getUptime(void) {
	return PV_napc_uptime;
}
