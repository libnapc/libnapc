#include <module/writer/_private/_writer.h>

bool libnapc_Writer_writeU16BE(
	libnapc__Writer *ctx, libnapc_u16 value
) {
	if (!PV_libnapc_Writer_checkAccess(ctx, 2, "u16")) {
		return false;
	}

	libnapc_u8 high_byte = (value >> 8u) & 0xFFu;
	libnapc_u8 low_byte  = (value >> 0u) & 0xFFU;

	unsigned char *data = ctx->data;
	data[ctx->_offset] = high_byte;
	data[ctx->_offset + 1] = low_byte;

	ctx->_offset += 2;

	return true;
}
