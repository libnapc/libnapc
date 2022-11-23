#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	napc__RingBuffer rbuffer;
	libnapc_u8 buffer[6] = {0,0,0,0,0,0xff};

	napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer) - 1);

	napc_RingBuffer_forceInsertByte(&rbuffer, 1);
	TEST_ASSERT(memcmp(buffer, "\x01\x00\x00\x00\x00\xff", 6) == 0);

	napc_RingBuffer_forceInsertByte(&rbuffer, 2);
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x00\x00\x00\xff", 6) == 0);

	napc_RingBuffer_forceInsertByte(&rbuffer, 3);
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x00\x00\xff", 6) == 0);

	napc_RingBuffer_forceInsertByte(&rbuffer, 4);
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x00\xff", 6) == 0);

	napc_RingBuffer_forceInsertByte(&rbuffer, 5);
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x05\xff", 6) == 0);

	// insertByte() would fail, but forceInsertByte() overwrites data
	napc_RingBuffer_forceInsertByte(&rbuffer, 6);
	TEST_ASSERT(memcmp(buffer, "\x06\x02\x03\x04\x05\xff", 6) == 0);

	napc_RingBuffer_forceInsertByte(&rbuffer, 7);
	TEST_ASSERT(memcmp(buffer, "\x06\x07\x03\x04\x05\xff", 6) == 0);

	napc_RingBuffer_forceInsertByte(&rbuffer, 8);
	napc_RingBuffer_forceInsertByte(&rbuffer, 9);
	napc_RingBuffer_forceInsertByte(&rbuffer, 0xa);
	napc_RingBuffer_forceInsertByte(&rbuffer, 0xb);

	TEST_ASSERT(memcmp(buffer, "\x0b\x07\x08\x09\xa\xff", 6) == 0);
}
