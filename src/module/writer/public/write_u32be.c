#include <module/writer/_private/_writer.h>

bool napc_Writer_writeU32BE(
	napc__Writer *ctx, libnapc_u32 value
) {
	if (!PV_napc_Writer_checkAccess(ctx, 4, "u32")) {
		return false;
	}

	libnapc_u8 byte_3 = (value >> 24u) & 0xFFu;
	libnapc_u8 byte_2 = (value >> 16u) & 0xFFu;
	libnapc_u8 byte_1 = (value >>  8u) & 0xFFu;
	libnapc_u8 byte_0 = (value >>  0u) & 0xFFu;

	unsigned char *data = ctx->data;
	data[ctx->_offset + 0] = byte_3;
	data[ctx->_offset + 1] = byte_2;
	data[ctx->_offset + 2] = byte_1;
	data[ctx->_offset + 3] = byte_0;

	ctx->_offset += 4;

	return true;
}
