#include <module/nf-writer/_private/_nf-writer.h>

void napc_NFWriter_writeU32BE(
	napc__NFWriter *ctx, napc_u32 value
) {
	NAPC_MAGIC_ASSERT(napc__NFWriter, ctx);

	NAPC_IGNORE_VALUE(
		napc_Writer_writeU32BE(&ctx->_writer, value)
	);
}
