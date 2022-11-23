#include <module/reader/_private/_reader.h>

bool napc_Reader_readString(
	napc__Reader *ctx,
	libnapc_size str_len,
	char *out,
	libnapc_size out_size
) {
	if (out && !out_size) {
		LIBNAPC_PANIC(
			"out_size cannot be zero inside napc_Reader_readString()."
		);
	}

	if (!PV_napc_Reader_checkAccess(ctx, str_len, "string")) {
		return false;
	} else if (((str_len + 1) > out_size) && out) {
		PV_NAPC_READER_ERROR("Reading string would overflow buffer.");

		return false;
	}

	if (out) {
		const char *data = ctx->data;

		for (libnapc_size i = 0; i < str_len; ++i) {
			out[i] = data[ctx->_offset + i];
		}
		// Terminate string
		out[str_len] = 0;
		// Always make sure string is terminated
		out[out_size - 1] = 0;
	}

	ctx->_offset += str_len;

	return true;
}
