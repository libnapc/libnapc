#include <module/nf-writer/_private/_nf-writer.h>

void napc_NFWriter_writeU16BE(
	napc__NFWriter *ctx, napc_u16 value
) {
	NAPC_MAGIC_ASSERT(napc__NFWriter, ctx);

	NAPC_IGNORE_VALUE(
		napc_Writer_writeU16BE(&ctx->_writer, value)
	);
}
