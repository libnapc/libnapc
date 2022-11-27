#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	libnapc__RingBuffer rbuffer;
	libnapc_u8 buffer[512];

	libnapc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer));

	TEST_ASSERT(libnapc_RingBuffer_getAvailableBytes(&rbuffer) == 0);

	for (int i = 0; i < 10; ++i) {
		libnapc_RingBuffer_insertByte(&rbuffer, i);
	}

	TEST_ASSERT(libnapc_RingBuffer_getAvailableBytes(&rbuffer) == 10);

	libnapc_RingBuffer_removeByte(&rbuffer, NULL);

	TEST_ASSERT(libnapc_RingBuffer_getAvailableBytes(&rbuffer) == 9);
}
