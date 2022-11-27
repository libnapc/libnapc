#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work properly") {
	libnapc_u8 payload[] = {
		0x1a,0x67,0x01,0x20,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x04,0x74,0x68,0x69,0x73,0x02,0x69,0x73,0x01,0x61,0x04,0x74,0x65,0x73,0x74,0x06,0x67,0x6f,0x6f,0x67,0x6c,0x65,0x03,0x63,0x6f,0x6d,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x29,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	};
	napc__DNSHeader header;

	TEST_ASSERT(
		libnapc_DNS_parseHeader(&header, payload, sizeof(payload))
	);

	TEST_ASSERT(header.request_identifier == LIBNAPC_U16_LITERAL(0x1a67));
	TEST_ASSERT(header.question_count == 1);
	TEST_ASSERT(header.answer_count == 0);
	TEST_ASSERT(header.response_code == 0);
}
