#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	libnapc__RingBuffer rbuffer;
	libnapc_u8 buffer[6] = {0,0,0,0,0,0xff};
	libnapc_u8 read_buffer_1[3] = {0,0,0};
	libnapc_u8 read_buffer_2[2] = {0,0};

	libnapc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer) - 1);

	libnapc_RingBuffer_insertByte(&rbuffer, 1);
	libnapc_RingBuffer_insertByte(&rbuffer, 2);
	libnapc_RingBuffer_insertByte(&rbuffer, 3);
	libnapc_RingBuffer_insertByte(&rbuffer, 4);
	libnapc_RingBuffer_insertByte(&rbuffer, 5);

	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x05\xff", 6) == 0);

	// read 3 bytes
	TEST_ASSERT(libnapc_RingBuffer_removeBytes(&rbuffer, read_buffer_1, sizeof(read_buffer_1)));
	TEST_ASSERT(read_buffer_1[0] == 1);
	TEST_ASSERT(read_buffer_1[1] == 2);
	TEST_ASSERT(read_buffer_1[2] == 3);

	// read 3 bytes again (should fail)
	TEST_ASSERT(!libnapc_RingBuffer_removeBytes(&rbuffer, read_buffer_1, sizeof(read_buffer_1)));

	// read 2 bytes
	TEST_ASSERT(libnapc_RingBuffer_removeBytes(&rbuffer, read_buffer_2, sizeof(read_buffer_2)));
	TEST_ASSERT(read_buffer_2[0] == 4);
	TEST_ASSERT(read_buffer_2[1] == 5);
}
