#include <napc.h>
#include <libnapc-testing.h>

TEST_CASE("should work as expected") {
	napc__RingBuffer rbuffer;
	napc_u8 buffer[6] = {0,0,0,0,0,0xff};
	napc_u8 tmp = 0;

	napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer) - 1);

	napc_RingBuffer_insertByte(&rbuffer, 1);
	napc_RingBuffer_insertByte(&rbuffer, 2);
	napc_RingBuffer_insertByte(&rbuffer, 3);
	napc_RingBuffer_insertByte(&rbuffer, 4);
	napc_RingBuffer_insertByte(&rbuffer, 5);

	TEST_ASSERT(memcmp(buffer, "\x01\x02\x03\x04\x05\xff", 6) == 0);

	TEST_ASSERT(napc_RingBuffer_peekByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 1);
	TEST_ASSERT(napc_RingBuffer_peekByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 1);

	napc_RingBuffer_removeByte(&rbuffer, NULL); // remove '1'
	napc_RingBuffer_removeByte(&rbuffer, NULL); // remove '2'
	napc_RingBuffer_removeByte(&rbuffer, NULL); // remove '3'
	napc_RingBuffer_removeByte(&rbuffer, NULL); // remove '4'

	TEST_ASSERT(napc_RingBuffer_peekByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 5);
	TEST_ASSERT(napc_RingBuffer_peekByte(&rbuffer, &tmp));
	TEST_ASSERT(tmp == 5);
}
