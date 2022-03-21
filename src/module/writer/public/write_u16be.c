#include <module/writer/_private/_writer.h>

bool napc_Writer_writeU16BE(
	napc__Writer *ctx, napc_u16 value
) {
	if (!PV_napc_Writer_checkAccess(ctx, 2, "u16")) {
		return false;
	}

	napc_u8 high_byte = (value >> 8u) & 0xFFu;
	napc_u8 low_byte  = (value >> 0u) & 0xFFU;

	unsigned char *data = ctx->data;
	data[ctx->_offset] = high_byte;
	data[ctx->_offset + 1] = low_byte;

	ctx->_offset += 2;

	return true;
}
