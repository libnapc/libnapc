#include <napc-core/_private/_napc-core.h>

bool PV_napc_validateAccessFailureMode(napc__AccessFailureMode mode) {
	if (mode == NAPC_ACCESS_FAILURE_MODE_NONE) return true;
	if (mode == NAPC_ACCESS_FAILURE_MODE_PANIC) return true;
	if (mode == NAPC_ACCESS_FAILURE_MODE_LOG) return true;

	return false;
}
