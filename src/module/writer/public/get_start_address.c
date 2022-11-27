#include <module/writer/_private/_writer.h>

void *libnapc_Writer_getStartAddress(
	const libnapc__Writer *ctx
) {
	LIBNAPC_MAGIC_ASSERT(napc__Writer, ctx);

	return ctx->data;
}
