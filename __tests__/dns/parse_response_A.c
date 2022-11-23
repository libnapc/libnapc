#include <napc.h>
#include <libnapc-testing.h>

TEST_CASE("should work properly (A record)") {
	napc_u8 payload[] = {
		0xef,0xc2,0x81,0x80,0x00,0x01,0x00,0x05,0x00,0x00,0x00,0x01,0x09,0x6d,0x69,0x63,0x72,0x6f,0x73,0x6f,0x66,0x74,0x03,0x63,0x6f,0x6d,0x00,0x00,0x01,0x00,0x01,0xc0,0x0c,0x00,0x01,0x00,0x01,0x00,0x00,0x08,0xfa,0x00,0x04,0x0d,0x4d,0xa1,0xb3,0xc0,0x0c,0x00,0x01,0x00,0x01,0x00,0x00,0x08,0xfa,0x00,0x04,0x28,0x70,0x48,0xcd,0xc0,0x0c,0x00,0x01,0x00,0x01,0x00,0x00,0x08,0xfa,0x00,0x04,0x28,0x4c,0x04,0x0f,0xc0,0x0c,0x00,0x01,0x00,0x01,0x00,0x00,0x08,0xfa,0x00,0x04,0x28,0x71,0xc8,0xc9,0xc0,0x0c,0x00,0x01,0x00,0x01,0x00,0x00,0x08,0xfa,0x00,0x04,0x68,0xd7,0x94,0x3f,0x00,0x00,0x29,0x04,0xd0,0x00,0x00,0x00,0x00,0x00,0x00
	};
	napc__DNSResponse response;

	TEST_ASSERT(
		napc_DNS_parseResponse(&response, payload, sizeof(payload))
	);

	TEST_ASSERT(response.header.question_count == 1);
	TEST_ASSERT(response.header.answer_count == 5);
	TEST_ASSERT(
		response.header.request_identifier == NAPC_U16_LITERAL(0xefc2)
	);
	TEST_ASSERT(response.header.response_code == 0);

	TEST_ASSERT(response.answers[0].ttl == 2298);
	TEST_ASSERT(response.answers[0].rd_length == 4);
	TEST_ASSERT(
		napc_memeql("\x0d\x4d\xa1\xb3", response.answers[0].rd_data, 4)
	);
}
