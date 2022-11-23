#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should work properly (A record)") {
	napc_u8 payload[] = {
		0xef,0xc2,0x01,0x20,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x09,0x6d,0x69,0x63,0x72,0x6f,0x73,0x6f,0x66,0x74,0x03,0x63,0x6f,0x6d,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x29,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	};
	napc__DNSRequest request;

	TEST_ASSERT(
		napc_DNS_parseRequest(&request, payload, sizeof(payload))
	);

	TEST_ASSERT(request.header.question_count == 1);
	TEST_ASSERT(request.header.answer_count == 0);
	TEST_ASSERT(
		request.header.request_identifier == NAPC_U16_LITERAL(0xefc2)
	);
	TEST_ASSERT(request.header.response_code == 0);

	TEST_ASSERT(request.query.qtype == NAPC_DNS_QTYPE_A);
	TEST_ASSERT(
		napc_streql("microsoft.com", request.query.name)
	);
}
