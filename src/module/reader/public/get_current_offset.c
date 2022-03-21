#include <module/reader/_private/_reader.h>

napc_size napc_Reader_getCurrentOffset(
	const napc__Reader *ctx
) {
	NAPC_MAGIC_ASSERT(napc__Reader, ctx);

	return ctx->_offset;
}
