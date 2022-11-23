#include <module/reader/_private/_reader.h>

bool napc_Reader_readU32BE(
	napc__Reader *ctx, libnapc_u32 *out
) {
	if (!PV_napc_Reader_checkAccess(ctx, 4, "u32")) {
		return false;
	}

	const unsigned char *data = ctx->data;
	napc_u8 byte_3 = data[ctx->_offset + 0];
	napc_u8 byte_2 = data[ctx->_offset + 1];
	napc_u8 byte_1 = data[ctx->_offset + 2];
	napc_u8 byte_0 = data[ctx->_offset + 3];

	libnapc_u32 result = 0;
	result |= (byte_0 <<  0u);
	result |= (byte_1 <<  8u);
	result |= (byte_2 << 16u);
	result |= (byte_3 << 24u);
	ctx->_offset += 4;

	if (out) {
		*out = result;
	}

	return true;
}
