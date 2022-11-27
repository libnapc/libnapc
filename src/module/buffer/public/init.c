#include <module/buffer/_private/_buffer.h>

void libnapc_Buffer_init(
	libnapc__Buffer *buffer, void *data, libnapc_size data_size
) {
	buffer->data = data;
	buffer->size = data_size;

	LIBNAPC_MAGIC_INIT(napc__Buffer, buffer);
}
