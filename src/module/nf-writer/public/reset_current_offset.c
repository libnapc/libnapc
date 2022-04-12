#include <module/nf-writer/_private/_nf-writer.h>

void napc_NFWriter_resetCurrentOffset(
	napc__NFWriter *ctx
) {
	NAPC_MAGIC_ASSERT(napc__NFWriter, ctx);

	napc_Writer_resetCurrentOffset(&ctx->_writer);
}
