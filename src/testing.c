#include <libnapc.h>
#include <stdio.h>

void PV_libnapc_testAssert(
	const char *assertion,
	const char *file,
	int expr
) {
	LIBNAPC_IGNORE_VALUE(file);

	if (!expr) {
		LIBNAPC_PANIC("Test assertion '%s' failed.", assertion);
	}
}
