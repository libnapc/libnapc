#include <module/nf-writer/_private/_nf-writer.h>

void napc_NFWriter_writeU8Array(
	napc__NFWriter *ctx,
	napc_size n_elements,
	const napc_u8 *array
) {
	NAPC_MAGIC_ASSERT(napc__NFWriter, ctx);

	NAPC_IGNORE_VALUE(
		napc_Writer_writeU8Array(&ctx->_writer, n_elements, array)
	);
}
