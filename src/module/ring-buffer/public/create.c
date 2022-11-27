#include <module/ring-buffer/_private/_ring-buffer.h>

napc__RingBuffer libnapc_RingBuffer_create(libnapc_u8 *buffer, libnapc_size buffer_size) {
	napc__RingBuffer rbuffer;

	libnapc_RingBuffer_init(&rbuffer, buffer, buffer_size);

	return rbuffer;
}
