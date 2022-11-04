#include <module/reader/_private/_reader.h>

void napc_Reader_setAccessFailureMode(
	napc__Reader *ctx, napc__ReaderFailMode mode
) {
	NAPC_MAGIC_ASSERT(napc__Reader, ctx);

	ctx->_fail_mode = mode;
}
