#include <libnapc.h>

libnapc_u8 buffer[5];

int main(int argc, const char **argv) {
	LIBNAPC_IGNORE_VALUE(argc);
	LIBNAPC_IGNORE_VALUE(argv);

	libnapc_init();

	libnapc__RingBuffer rbuffer = libnapc_RingBuffer_create(buffer, sizeof(buffer));

	libnapc_RingBuffer_setAccessFailureMode(&rbuffer, LIBNAPC_ACCESS_FAILURE_MODE_PANIC);

	libnapc_RingBuffer_insertByte(&rbuffer, 10);
	libnapc_RingBuffer_insertByte(&rbuffer, 10);
	libnapc_RingBuffer_insertByte(&rbuffer, 10);
	libnapc_RingBuffer_insertByte(&rbuffer, 10);
	libnapc_RingBuffer_insertByte(&rbuffer, 10);

	libnapc_printf("crash:\n");
	libnapc_RingBuffer_insertByte(&rbuffer, 10);
}
