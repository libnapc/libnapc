#include <module/writer/_private/_writer.h>

bool PV_libnapc_Writer_checkAccess(
	libnapc__Writer *ctx, libnapc_size type_size, const char *type
) {
	LIBNAPC_MAGIC_ASSERT(napc__Writer, ctx);

	libnapc_size new_offset = ctx->_offset + type_size;

	if (new_offset > ctx->size) {
		if (ctx->_fail_mode == LIBNAPC_ACCESS_FAILURE_MODE_LOG) {
			PV_LIBNAPC_WRITER_ERROR(
				"Refusing to write type '%s' (size=%" LIBNAPC_SIZE_PRINT_DEC ") to buffer"
				" (offset=%" LIBNAPC_SIZE_PRINT_DEC ",size=%" LIBNAPC_SIZE_PRINT_DEC ")",
				type,
				type_size,
				ctx->_offset,
				ctx->size
			);
		} else if (LIBNAPC_UNLIKELY(ctx->_fail_mode == LIBNAPC_ACCESS_FAILURE_MODE_PANIC)) {
			LIBNAPC_PANIC(
				"Write operation failed and fail mode is set to LIBNAPC_ACCESS_FAILURE_MODE_PANIC."
			);
		}

		return false;
	}

	return true;
}
