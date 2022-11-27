#include <module/reader/_private/_reader.h>

const void *libnapc_Reader_getStartAddress(
	const libnapc__Reader *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Reader, ctx);

	return ctx->data;
}
