#include <module/reader/_private/_reader.h>

void libnapc_Reader_init(
	libnapc__Reader *ctx, const void *data, libnapc_size data_size
) {
	if (!data_size) {
		LIBNAPC_PANIC("Size cannot be zero inside libnapc_Reader_init().");
	}

	ctx->_fail_mode = PV_libnapc_getDefaultAccessFailureMode();

	ctx->data = data;
	ctx->size = data_size;
	ctx->_offset = 0;
	LIBNAPC_MAGIC_INIT(napc__Reader, ctx);
}
