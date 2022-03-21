#include <module/writer/_private/_writer.h>

void napc_Writer_resetCurrentOffset(
	napc__Writer *ctx
) {
	NAPC_MAGIC_ASSERT(napc__Writer, ctx);

	ctx->_offset = 0;
}
