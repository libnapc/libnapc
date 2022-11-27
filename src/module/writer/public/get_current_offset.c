#include <module/writer/_private/_writer.h>

libnapc_size napc_Writer_getCurrentOffset(
	const napc__Writer *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Writer, ctx);

	return ctx->_offset;
}
