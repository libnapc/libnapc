#include <module/writer/_private/_writer.h>

void napc_Writer_init(
	napc__Writer *ctx, void *data, napc_size data_size
) {
	NAPC_MAGIC_INIT(napc__Writer, ctx);
	ctx->data = data;
	ctx->size = data_size;
	ctx->_offset = 0;
}
