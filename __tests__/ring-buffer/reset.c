#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	libnapc__RingBuffer rbuffer;
	libnapc_u8 buffer[6] = {0,0,0,0,0,0xff};

	libnapc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer) - 1);

	libnapc_RingBuffer_insertByte(&rbuffer, 1);
	libnapc_RingBuffer_insertByte(&rbuffer, 2);
	libnapc_RingBuffer_insertByte(&rbuffer, 3);
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x00\x00\xff", 6) == 0);

	libnapc_RingBuffer_reset(&rbuffer);

	TEST_ASSERT(libnapc_RingBuffer_getAvailableBytes(&rbuffer) == 0);

	libnapc_RingBuffer_insertByte(&rbuffer, 4);
	libnapc_RingBuffer_insertByte(&rbuffer, 5);
	libnapc_RingBuffer_insertByte(&rbuffer, 6);

	TEST_ASSERT(memcmp(buffer, "\x04\x05\x06\x00\x00\xff", 6) == 0);
}
