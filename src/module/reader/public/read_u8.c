#include <module/reader/_private/_reader.h>

bool libnapc_Reader_readU8(
	libnapc__Reader *ctx, libnapc_u8 *out
) {
	if (!PV_libnapc_Reader_checkAccess(ctx, 1, "u8")) {
		return false;
	}

	const unsigned char *data = ctx->data;
	libnapc_u8 result = data[ctx->_offset];
	ctx->_offset += 1;

	if (out) {
		*out = result;
	}

	return true;
}
