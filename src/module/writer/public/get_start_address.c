#include <module/writer/_private/_writer.h>

void *napc_Writer_getStartAddress(
	const napc__Writer *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Writer, ctx);

	return ctx->data;
}
