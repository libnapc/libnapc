#include <napc.h>
#include <napc-testing.h>

TEST_CASE("should work as expected") {
	napc__RingBuffer rbuffer;
	napc_u8 buffer[6] = {0,0,0,0,0,0xff};

	napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer) - 1);

	napc_RingBuffer_insertByte(&rbuffer, 1);
	napc_RingBuffer_insertByte(&rbuffer, 2);
	napc_RingBuffer_insertByte(&rbuffer, 3);
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x00\x00\xff", 6) == 0);

	napc_RingBuffer_reset(&rbuffer);

	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 0);

	napc_RingBuffer_insertByte(&rbuffer, 4);
	napc_RingBuffer_insertByte(&rbuffer, 5);
	napc_RingBuffer_insertByte(&rbuffer, 6);

	TEST_ASSERT(memcmp(buffer, "\x04\x05\x06\x00\x00\xff", 6) == 0);
}
