#include <module/ring-buffer/_private/_ring-buffer.h>

napc__RingBuffer napc_RingBuffer_create(napc_u8 *buffer, napc_size buffer_size) {
	napc__RingBuffer rbuffer;

	napc_RingBuffer_init(&rbuffer, buffer, buffer_size);

	return rbuffer;
}
