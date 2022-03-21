#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_hmac__testCase7(void) {
    napc_unmute();
    napc_puts("[hmac/calculate.c] It should work properly ... ");
    napc_mute();
	const char *message = "hello world! this is a test";
	const char *key = "test";

	const napc_u8 expected_hmac[32] = {
		0x85,
		0x98,
		0x64,
		0xd6,
		0xe5,
		0x82,
		0x6a,
		0x3b,
		0x39,
		0xe2,
		0x63,
		0x1f,
		0x79,
		0x6b,
		0xd1,
		0xa8,
		0x58,
		0x33,
		0x71,
		0xb2,
		0xd4,
		0x34,
		0x22,
		0x6f,
		0x8a,
		0xfb,
		0x28,
		0xc6,
		0x74,
		0x19,
		0x84,
		0x8e
	};

	napc_u8 hmac[32];

	napc_hmac_calculate(hmac, key, message, napc_strlen(message));

	TEST_ASSERT(
		memcmp(hmac, expected_hmac, sizeof(hmac)) == 0
	);
}
