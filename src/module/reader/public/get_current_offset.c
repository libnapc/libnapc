#include <module/reader/_private/_reader.h>

libnapc_size napc_Reader_getCurrentOffset(
	const napc__Reader *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Reader, ctx);

	return ctx->_offset;
}
