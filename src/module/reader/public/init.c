#include <module/reader/_private/_reader.h>

void napc_Reader_init(
	napc__Reader *ctx, const void *data, libnapc_size data_size
) {
	if (!data_size) {
		LIBNAPC_PANIC("Size cannot be zero inside napc_Reader_init().");
	}

	ctx->_fail_mode = PV_napc_getDefaultAccessFailureMode();

	ctx->data = data;
	ctx->size = data_size;
	ctx->_offset = 0;
	NAPC_MAGIC_INIT(napc__Reader, ctx);
}
