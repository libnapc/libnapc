#include <libnapc.h>
void libnapc_callBootFunctions(void);

napc_u8 buffer[5];

int main(int argc, const char **argv) {
	NAPC_IGNORE_VALUE(argc);
	NAPC_IGNORE_VALUE(argv);

	libnapc_callBootFunctions();

	napc__RingBuffer rbuffer = napc_RingBuffer_create(buffer, sizeof(buffer));

	napc_RingBuffer_setAccessFailureMode(&rbuffer, NAPC_ACCESS_FAILURE_MODE_PANIC);

	napc_RingBuffer_insertByte(&rbuffer, 10);
	napc_RingBuffer_insertByte(&rbuffer, 10);
	napc_RingBuffer_insertByte(&rbuffer, 10);
	napc_RingBuffer_insertByte(&rbuffer, 10);
	napc_RingBuffer_insertByte(&rbuffer, 10);

	napc_printf("crash:\n");
	napc_RingBuffer_insertByte(&rbuffer, 10);
}

bool napc_app_loop(napc_time uptime) {
	NAPC_IGNORE_VALUE(uptime);

	return false;
}
