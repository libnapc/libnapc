#include <module/reader/_private/_reader.h>

void napc_Reader_setAccessFailureMode(
	napc__Reader *ctx, libnapc__AccessFailureMode mode
) {
	NAPC_MAGIC_ASSERT(napc__Reader, ctx);

	if (LIBNAPC_UNLIKELY(!PV_libnapc_validateAccessFailureMode(mode))) {
		LIBNAPC_PANIC("Unrecognized AccessFailureMode '%d'", mode);
	}

	ctx->_fail_mode = mode;
}
