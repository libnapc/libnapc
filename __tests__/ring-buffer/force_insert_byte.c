#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	libnapc__RingBuffer rbuffer;
	libnapc_u8 buffer[6] = {0,0,0,0,0,0xff};

	libnapc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer) - 1);

	libnapc_RingBuffer_forceInsertByte(&rbuffer, 1);
	TEST_ASSERT(memcmp(buffer, "\x01\x00\x00\x00\x00\xff", 6) == 0);

	libnapc_RingBuffer_forceInsertByte(&rbuffer, 2);
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x00\x00\x00\xff", 6) == 0);

	libnapc_RingBuffer_forceInsertByte(&rbuffer, 3);
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x00\x00\xff", 6) == 0);

	libnapc_RingBuffer_forceInsertByte(&rbuffer, 4);
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x00\xff", 6) == 0);

	libnapc_RingBuffer_forceInsertByte(&rbuffer, 5);
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x05\xff", 6) == 0);

	// insertByte() would fail, but forceInsertByte() overwrites data
	libnapc_RingBuffer_forceInsertByte(&rbuffer, 6);
	TEST_ASSERT(memcmp(buffer, "\x06\x02\x03\x04\x05\xff", 6) == 0);

	libnapc_RingBuffer_forceInsertByte(&rbuffer, 7);
	TEST_ASSERT(memcmp(buffer, "\x06\x07\x03\x04\x05\xff", 6) == 0);

	libnapc_RingBuffer_forceInsertByte(&rbuffer, 8);
	libnapc_RingBuffer_forceInsertByte(&rbuffer, 9);
	libnapc_RingBuffer_forceInsertByte(&rbuffer, 0xa);
	libnapc_RingBuffer_forceInsertByte(&rbuffer, 0xb);

	TEST_ASSERT(memcmp(buffer, "\x0b\x07\x08\x09\xa\xff", 6) == 0);
}
