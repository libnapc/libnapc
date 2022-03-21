#include <module/reader/_private/_reader.h>

const void *napc_Reader_getEndAddress(
	const napc__Reader *ctx
) {
	NAPC_MAGIC_ASSERT(napc__Reader, ctx);

	const unsigned char *base = ctx->data;

	return base + (ctx->size - 1);
}
