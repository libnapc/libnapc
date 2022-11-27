#include <module/writer/_private/_writer.h>

bool napc_Writer_moveCurrentOffsetByAmount(
	napc__Writer *ctx, libnapc_ssize amount
) {
	LIBNAPC_MAGIC_ASSERT(napc__Writer, ctx);

	libnapc_size new_offset = ctx->_offset + amount;

	// if new_offset goes negative, it will turn
	// into a huge number (positive integer underflow is well-defined)
	if (new_offset >= ctx->size) {
		return false;
	}

	ctx->_offset = new_offset;

	return true;
}
