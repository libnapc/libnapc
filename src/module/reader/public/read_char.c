#include <module/reader/_private/_reader.h>

bool napc_Reader_readChar(
	napc__Reader *ctx, char *out
) {
	if (!PV_napc_Reader_checkAccess(ctx, 1, "char")) {
		return false;
	}

	const char *data = ctx->data;
	char result = data[ctx->_offset];
	ctx->_offset += 1;

	if (out) {
		*out = result;
	}

	return true;
}
