#include <module/writer/_private/_writer.h>

void napc_Writer_setAccessFailureMode(
	napc__Writer *ctx, napc__AccessFailureMode mode
) {
	NAPC_MAGIC_ASSERT(napc__Writer, ctx);

	if (NAPC_UNLIKELY(!PV_napc_validateAccessFailureMode(mode))) {
		NAPC_PANIC("Unrecognized AccessFailureMode '%d'", mode);
	}

	ctx->_fail_mode = mode;
}
