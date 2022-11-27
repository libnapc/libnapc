#include <module/reader/_private/_reader.h>

libnapc_size libnapc_Reader_getRemainingBytes(
	const libnapc__Reader *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Reader, ctx);

	return ctx->size - ctx->_offset;
}
