#include <module/reader/_private/_reader.h>

const void *libnapc_Reader_getEndAddress(
	const napc__Reader *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Reader, ctx);

	const unsigned char *base = ctx->data;

	return base + (ctx->size - 1);
}
