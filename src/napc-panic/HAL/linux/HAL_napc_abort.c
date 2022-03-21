#if !defined(ARDUINO)
	#include <napc-panic/_private/_napc-panic.h>
	#include <stdlib.h> // exit(), EXIT_FAILURE

	void HAL_napc_abort(void) {
		exit(EXIT_FAILURE);
	}
#endif
