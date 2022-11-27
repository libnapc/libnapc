#include <module/writer/_private/_writer.h>

void libnapc_Writer_setAccessFailureMode(
	napc__Writer *ctx, libnapc__AccessFailureMode mode
) {
	LIBNAPC_MAGIC_ASSERT(napc__Writer, ctx);

	if (LIBNAPC_UNLIKELY(!PV_libnapc_validateAccessFailureMode(mode))) {
		LIBNAPC_PANIC("Unrecognized AccessFailureMode '%d'", mode);
	}

	ctx->_fail_mode = mode;
}
