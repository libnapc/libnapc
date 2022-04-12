#include <module/nf-writer/_private/_nf-writer.h>

napc_size napc_NFWriter_getCurrentOffset(
	const napc__NFWriter *ctx
) {
	NAPC_MAGIC_ASSERT(napc__NFWriter, ctx);

	return napc_Writer_getCurrentOffset(&ctx->_writer);
}
