#include <module/nf-writer/_private/_nf-writer.h>

void napc_NFWriter_writeString(
	napc__NFWriter *ctx, const char *value
) {
	NAPC_MAGIC_ASSERT(napc__NFWriter, ctx);

	NAPC_IGNORE_VALUE(
		napc_Writer_writeString(&ctx->_writer, value)
	);
}
