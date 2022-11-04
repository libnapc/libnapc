#include <module/writer/_private/_writer.h>

void napc_Writer_setAccessFailureMode(
	napc__Writer *ctx, napc__WriterFailMode mode
) {
	NAPC_MAGIC_ASSERT(napc__Writer, ctx);

	ctx->_fail_mode = mode;
}
