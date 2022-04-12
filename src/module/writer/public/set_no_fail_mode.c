#include <module/writer/_private/_writer.h>

bool napc_Writer_setNoFailMode(
	napc__Writer *ctx, bool mode
) {
	NAPC_MAGIC_ASSERT(napc__Writer, ctx);

	bool previous_mode = ctx->no_fail_mode;

	ctx->no_fail_mode = mode;

	return previous_mode;
}
