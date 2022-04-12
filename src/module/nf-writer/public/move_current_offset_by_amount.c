#include <module/nf-writer/_private/_nf-writer.h>

void napc_NFWriter_moveCurrentOffsetByAmount(
	napc__NFWriter *ctx, napc_ssize amount
) {
	NAPC_MAGIC_ASSERT(napc__NFWriter, ctx);

	if (!napc_Writer_moveCurrentOffsetByAmount(&ctx->_writer, amount)) {
		NAPC_PANIC("Failed to move NFWriter offset.");
	}
}
