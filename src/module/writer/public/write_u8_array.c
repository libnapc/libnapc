#include <module/writer/_private/_writer.h>

bool napc_Writer_writeU8Array(
	napc__Writer *ctx,
	libnapc_size n_elements,
	const libnapc_u8 *array
) {
	if (!PV_napc_Writer_checkAccess(ctx, n_elements, "u8_array")) {
		return false;
	}

	unsigned char *data = ctx->data;

	for (libnapc_size i = 0; i < n_elements; ++i) {
		data[ctx->_offset + i] = array[i];
	}

	ctx->_offset += n_elements;

	return true;
}
