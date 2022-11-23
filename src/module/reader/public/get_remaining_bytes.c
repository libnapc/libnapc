#include <module/reader/_private/_reader.h>

libnapc_size napc_Reader_getRemainingBytes(
	const napc__Reader *ctx
) {
	NAPC_MAGIC_ASSERT(napc__Reader, ctx);

	return ctx->size - ctx->_offset;
}
