#include <module/nf-writer/_private/_nf-writer.h>

void napc_NFWriter_writeChar(
	napc__NFWriter *ctx, char value
) {
	NAPC_MAGIC_ASSERT(napc__NFWriter, ctx);

	NAPC_IGNORE_VALUE(
		napc_Writer_writeChar(&ctx->_writer, value)
	);
}
