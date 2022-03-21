#include <module/writer/_private/_writer.h>

napc_size napc_Writer_getCurrentOffset(
	const napc__Writer *ctx
) {
	NAPC_MAGIC_ASSERT(napc__Writer, ctx);

	return ctx->_offset;
}
