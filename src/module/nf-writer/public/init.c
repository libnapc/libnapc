#include <module/nf-writer/_private/_nf-writer.h>

void napc_NFWriter_init(
	napc__NFWriter *ctx, void *data, napc_size data_size
) {
	NAPC_MAGIC_INIT(napc__NFWriter, ctx);

	ctx->_writer = napc_Writer_create(data, data_size);

	napc_Writer_setNoFailMode(&ctx->_writer, true);
}
