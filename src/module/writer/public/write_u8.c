#include <module/writer/_private/_writer.h>

bool napc_Writer_writeU8(
	napc__Writer *ctx, napc_u8 value
) {
	if (!PV_napc_Writer_checkAccess(ctx, 1, "u8")) {
		return false;
	}

	unsigned char *data = ctx->data;
	data[ctx->_offset] = value;
	ctx->_offset += 1;

	return true;
}
