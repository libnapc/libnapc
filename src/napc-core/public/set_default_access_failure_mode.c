#include <napc-core/_private/_napc-core.h>

napc__AccessFailureMode napc_setDefaultAccessFailureMode(
	napc__AccessFailureMode new_default_mode
) {
	if (NAPC_UNLIKELY(!PV_napc_validateAccessFailureMode(new_default_mode))) {
		LIBNAPC_PANIC("Unrecognized AccessFailureMode '%d'", new_default_mode);
	}

	napc__AccessFailureMode current = PV_napc_default_access_failure_mode;

	PV_napc_default_access_failure_mode = new_default_mode;

	return current;
}
