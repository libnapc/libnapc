#include <libnapc-core/_private/_libnapc-core.h>

libnapc__AccessFailureMode libnapc_setDefaultAccessFailureMode(
	libnapc__AccessFailureMode new_default_mode
) {
	if (LIBNAPC_UNLIKELY(!PV_libnapc_validateAccessFailureMode(new_default_mode))) {
		LIBNAPC_PANIC("Unrecognized AccessFailureMode '%d'", new_default_mode);
	}

	libnapc__AccessFailureMode current = PV_libnapc_default_access_failure_mode;

	PV_libnapc_default_access_failure_mode = new_default_mode;

	return current;
}
