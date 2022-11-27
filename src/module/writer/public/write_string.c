#include <module/writer/_private/_writer.h>

bool libnapc_Writer_writeString(
	napc__Writer *ctx, const char *value
) {
	libnapc_size str_len = libnapc_strlen(value);

	if (!PV_libnapc_Writer_checkAccess(ctx, str_len, "string")) {
		return false;
	}

	char *data = ctx->data;

	for (libnapc_size i = 0; i < str_len; ++i) {
		data[ctx->_offset + i] = value[i];
	}

	ctx->_offset += str_len;

	return true;
}
