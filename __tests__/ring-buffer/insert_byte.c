#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	napc__RingBuffer rbuffer;
	napc_u8 buffer[6] = {0,0,0,0,0,0xff};

	napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer) - 1);

	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 1));
	TEST_ASSERT(memcmp(buffer, "\x01\x00\x00\x00\x00\xff", 6) == 0);

	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 2));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x00\x00\x00\xff", 6) == 0);

	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 3));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x00\x00\xff", 6) == 0);

	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 4));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x00\xff", 6) == 0);

	TEST_ASSERT(napc_RingBuffer_insertByte(&rbuffer, 5));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x05\xff", 6) == 0);

	TEST_ASSERT(!napc_RingBuffer_insertByte(&rbuffer, 6));
	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x05\xff", 6) == 0);
}
