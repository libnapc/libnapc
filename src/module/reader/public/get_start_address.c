#include <module/reader/_private/_reader.h>

const void *napc_Reader_getStartAddress(
	const napc__Reader *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Reader, ctx);

	return ctx->data;
}
