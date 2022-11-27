#include <module/reader/_private/_reader.h>

const void *napc_Reader_getCurrentAddress(
	const napc__Reader *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Reader, ctx);

	const unsigned char *base = ctx->data;

	return base + (ctx->_offset);
}
