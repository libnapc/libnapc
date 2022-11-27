#include <module/writer/_private/_writer.h>

void *libnapc_Writer_getEndAddress(
	const napc__Writer *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Writer, ctx);

	unsigned char *base = ctx->data;

	return base + (ctx->size - 1);
}
