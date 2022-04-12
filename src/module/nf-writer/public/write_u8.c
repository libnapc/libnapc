#include <module/nf-writer/_private/_nf-writer.h>

void napc_NFWriter_writeU8(
	napc__NFWriter *ctx, napc_u8 value
) {
	NAPC_MAGIC_ASSERT(napc__NFWriter, ctx);

	NAPC_IGNORE_VALUE(
		napc_Writer_writeU8(&ctx->_writer, value)
	);
}
