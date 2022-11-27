#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	napc__RingBuffer rbuffer;
	libnapc_u8 buffer[512];

	libnapc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer));

	TEST_ASSERT(
		libnapc_RingBuffer_getBufferSize(&rbuffer) == 512
	);
}
