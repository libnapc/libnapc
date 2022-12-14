#include <module/writer/_private/_writer.h>

bool libnapc_Writer_writeU8(
	libnapc__Writer *ctx, libnapc_u8 value
) {
	if (!PV_libnapc_Writer_checkAccess(ctx, 1, "u8")) {
		return false;
	}

	unsigned char *data = ctx->data;
	data[ctx->_offset] = value;
	ctx->_offset += 1;

	return true;
}
