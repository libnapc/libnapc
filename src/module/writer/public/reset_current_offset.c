#include <module/writer/_private/_writer.h>

void libnapc_Writer_resetCurrentOffset(
	napc__Writer *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Writer, ctx);

	ctx->_offset = 0;
}
