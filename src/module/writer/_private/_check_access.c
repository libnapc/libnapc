#include <module/writer/_private/_writer.h>

bool PV_napc_Writer_checkAccess(
	napc__Writer *ctx, napc_size type_size, const char *type
) {
	NAPC_MAGIC_ASSERT(napc__Writer, ctx);

	napc_size new_offset = ctx->_offset + type_size;

	if (new_offset > ctx->size) {
		PV_NAPC_WRITER_ERROR(
			"Refusing to write type '%s' (size=%" NAPC_SIZE_PRINTF ") to buffer"
			" (offset=%" NAPC_SIZE_PRINTF ",size=%" NAPC_SIZE_PRINTF ")",
			type,
			type_size,
			ctx->_offset,
			ctx->size
		);

		if (ctx->no_fail_mode) {
			NAPC_PANIC(
				"Write operation failed and no_fail_mode is set to true."
			);
		}

		return false;
	}

	return true;
}
