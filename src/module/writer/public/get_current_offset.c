#include <module/writer/_private/_writer.h>

libnapc_size libnapc_Writer_getCurrentOffset(
	const libnapc__Writer *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Writer, ctx);

	return ctx->_offset;
}
