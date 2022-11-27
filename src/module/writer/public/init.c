#include <module/writer/_private/_writer.h>

void libnapc_Writer_init(
	libnapc__Writer *ctx, void *data, libnapc_size data_size
) {
	LIBNAPC_MAGIC_INIT(napc__Writer, ctx);

	ctx->_fail_mode = PV_libnapc_getDefaultAccessFailureMode();

	ctx->data = data;
	ctx->size = data_size;
	ctx->_offset = 0;
}
