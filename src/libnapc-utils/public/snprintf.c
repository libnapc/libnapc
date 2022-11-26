#include <libnapc-utils/_private/_libnapc-utils.h>

void libnapc_snprintf(
	char *buffer,
	libnapc_size buffer_size,
	const char *fmt,
	...
) {
	va_list args;

	va_start(args, fmt);
	libnapc_vsnprintf(buffer, buffer_size, fmt, args);
	va_end(args);
}
