#include <module/nf-writer/_private/_nf-writer.h>

static char _tmp_buffer[128]; // @static

void napc_NFWriter_writeStringFormat(
	napc__NFWriter *ctx, const char *fmt, ...
) {
	NAPC_MAGIC_ASSERT(napc__NFWriter, ctx);

	va_list args;
	va_start(args, fmt);
	napc_vsnprintf(_tmp_buffer, sizeof(_tmp_buffer), fmt, args);
	va_end(args);

	napc_NFWriter_writeString(ctx, _tmp_buffer);
}
