#include <module/reader/_private/_reader.h>

bool napc_Reader_readU8Array(
	napc__Reader *ctx,
	napc_size n_elements,
	napc_u8 *out
) {
	if (!PV_napc_Reader_checkAccess(ctx, n_elements, "u8_array")) {
		return false;
	}

	if (out) {
		const unsigned char *data = ctx->data;

		for (napc_size i = 0; i < n_elements; ++i) {
			out[i] = data[ctx->_offset + i];
		}
	}

	ctx->_offset += n_elements;

	return true;
}
