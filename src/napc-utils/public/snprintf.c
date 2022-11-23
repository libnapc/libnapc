#include <napc-utils/_private/_napc-utils.h>

void libnapc_snprintf(
	char *buffer,
	napc_size buffer_size,
	const char *fmt,
	...
) {
	va_list args;

	va_start(args, fmt);
	napc_vsnprintf(buffer, buffer_size, fmt, args);
	va_end(args);
}
