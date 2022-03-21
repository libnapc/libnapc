#include <module/reader/_private/_reader.h>

bool napc_Reader_readU8(
	napc__Reader *ctx, napc_u8 *out
) {
	if (!PV_napc_Reader_checkAccess(ctx, 1, "u8")) {
		return false;
	}

	const unsigned char *data = ctx->data;
	napc_u8 result = data[ctx->_offset];
	ctx->_offset += 1;

	if (out) {
		*out = result;
	}

	return true;
}
