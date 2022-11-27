#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	libnapc__RingBuffer rbuffer;
	libnapc_u8 buffer[6] = {0,0,0,0,0,0xff};
	libnapc_u8 insert_array_1[3] = {1,2,3};
	libnapc_u8 insert_array_2[3] = {4,5,6};
	libnapc_u8 insert_array_3[2] = {4,5};

	libnapc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer) - 1);

	TEST_ASSERT(libnapc_RingBuffer_insertBytes(&rbuffer, insert_array_1, sizeof(insert_array_1)));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x00\x00\xff", 6) == 0);

	TEST_ASSERT(!libnapc_RingBuffer_insertBytes(&rbuffer, insert_array_2, sizeof(insert_array_2)));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x00\x00\xff", 6) == 0);

	TEST_ASSERT(libnapc_RingBuffer_insertBytes(&rbuffer, insert_array_3, sizeof(insert_array_3)));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x05\xff", 6) == 0);
}
