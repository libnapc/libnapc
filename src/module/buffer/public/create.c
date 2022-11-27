#include <module/buffer/_private/_buffer.h>

libnapc__Buffer libnapc_Buffer_create(void *data, libnapc_size data_size) {
	libnapc__Buffer buffer;

	libnapc_Buffer_init(&buffer, data, data_size);

	return buffer;
}
