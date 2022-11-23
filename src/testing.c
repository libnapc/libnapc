#include <libnapc.h>
#include <stdio.h>

void PV_napc_testAssert(
	const char *assertion,
	const char *file,
	int expr
) {
	NAPC_IGNORE_VALUE(file);

	if (!expr) {
		LIBNAPC_PANIC("Assertion '%s' failed.", assertion);
	}
}
