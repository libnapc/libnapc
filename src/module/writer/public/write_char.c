#include <module/writer/_private/_writer.h>

bool napc_Writer_writeChar(
	napc__Writer *ctx, char value
) {
	if (!PV_napc_Writer_checkAccess(ctx, 1, "char")) {
		return false;
	}

	char *data = ctx->data;
	data[ctx->_offset] = value;
	ctx->_offset += 1;

	return true;
}
