#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	napc__RingBuffer rbuffer;
	napc_u8 buffer[512];

	napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer));

	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 0);

	for (int i = 0; i < 10; ++i) {
		napc_RingBuffer_insertByte(&rbuffer, i);
	}

	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 10);

	napc_RingBuffer_removeByte(&rbuffer, NULL);

	TEST_ASSERT(napc_RingBuffer_getAvailableBytes(&rbuffer) == 9);
}
