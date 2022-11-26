#include <module/reader/_private/_reader.h>

bool PV_napc_Reader_checkAccess(
	napc__Reader *ctx, libnapc_size type_size, const char *type
) {
	NAPC_MAGIC_ASSERT(napc__Reader, ctx);

	libnapc_size new_offset = ctx->_offset + type_size;

	if (new_offset > ctx->size) {
		if (ctx->_fail_mode == LIBNAPC_ACCESS_FAILURE_MODE_LOG) {
			PV_NAPC_READER_ERROR(
				"Refusing to read type '%s' (size=%" LIBNAPC_SIZE_PRINT_DEC ") from buffer"
				" (offset=%" LIBNAPC_SIZE_PRINT_DEC ",size=%" LIBNAPC_SIZE_PRINT_DEC ")",
				type,
				type_size,
				ctx->_offset,
				ctx->size
			);
		} else if (LIBNAPC_UNLIKELY(ctx->_fail_mode == LIBNAPC_ACCESS_FAILURE_MODE_PANIC)) {
			LIBNAPC_PANIC(
				"Read operation failed and fail mode is set to LIBNAPC_ACCESS_FAILURE_MODE_PANIC."
			);
		}

		return false;
	}

	return true;
}
