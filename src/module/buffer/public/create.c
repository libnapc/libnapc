#include <module/buffer/_private/_buffer.h>

napc__Buffer napc_Buffer_create(void *data, libnapc_size data_size) {
	napc__Buffer buffer;

	napc_Buffer_init(&buffer, data, data_size);

	return buffer;
}
