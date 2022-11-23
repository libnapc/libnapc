#include <module/writer/_private/_writer.h>

bool PV_napc_Writer_checkAccess(
	napc__Writer *ctx, napc_size type_size, const char *type
) {
	NAPC_MAGIC_ASSERT(napc__Writer, ctx);

	napc_size new_offset = ctx->_offset + type_size;

	if (new_offset > ctx->size) {
		if (ctx->_fail_mode == LIBNAPC_ACCESS_FAILURE_MODE_LOG) {
			PV_NAPC_WRITER_ERROR(
				"Refusing to write type '%s' (size=%" NAPC_SIZE_PRINTF ") to buffer"
				" (offset=%" NAPC_SIZE_PRINTF ",size=%" NAPC_SIZE_PRINTF ")",
				type,
				type_size,
				ctx->_offset,
				ctx->size
			);
		} else if (NAPC_UNLIKELY(ctx->_fail_mode == LIBNAPC_ACCESS_FAILURE_MODE_PANIC)) {
			LIBNAPC_PANIC(
				"Write operation failed and fail mode is set to LIBNAPC_ACCESS_FAILURE_MODE_PANIC."
			);
		}

		return false;
	}

	return true;
}
