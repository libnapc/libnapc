#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("It should work properly") {
	const char *message = "hello world!";
	const char *key = "test";

	const libnapc_u8 message_hmac[32] = {
		0x14,
		0x82,
		0x0d,
		0x5a,
		0x03,
		0x56,
		0x95,
		0x5a,
		0x21,
		0xb6,
		0xd2,
		0x0d,
		0x0e,
		0xb1,
		0x86,
		0x30,
		0x90,
		0xe4,
		0x43,
		0x89,
		0xa9,
		0x2c,
		0x8b,
		0x2c,
		0x23,
		0xfd,
		0xd3,
		0x7f,
		0x3b,
		0xc9,
		0x87,
		0x7a
	};

	TEST_ASSERT(
		libnapc_hmac_verify(key, message_hmac, message, libnapc_strlen(message))
	);

	TEST_ASSERT(
		!libnapc_hmac_verify(key, message_hmac, "test", libnapc_strlen("test"))
	);
}
