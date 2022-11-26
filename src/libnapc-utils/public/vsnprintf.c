#include <libnapc-utils/_private/_libnapc-utils.h>

void libnapc_vsnprintf(
	char *buffer,
	libnapc_size buffer_size,
	const char *fmt,
	va_list args
) {
	memset(buffer, 0, buffer_size);

	vsnprintf(buffer, buffer_size, fmt, args);

	// make sure buffer is always terminated (vsnprintf doesn't do that)
	buffer[buffer_size - 1] = 0;
}
