#include <module/reader/_private/_reader.h>

bool libnapc_Reader_readU16BE(
	libnapc__Reader *ctx, libnapc_u16 *out
) {
	if (!PV_libnapc_Reader_checkAccess(ctx, 2, "u16")) {
		return false;
	}

	const unsigned char *data = ctx->data;
	libnapc_u8 high_byte = data[ctx->_offset];
	libnapc_u8 low_byte = data[ctx->_offset + 1];
	libnapc_u16 result = (high_byte << 8u) | low_byte;
	ctx->_offset += 2;

	if (out) {
		*out = result;
	}

	return true;
}
