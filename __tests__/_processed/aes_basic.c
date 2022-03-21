#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_aes__testCase1(void) {
    napc_unmute();
    napc_puts("[aes/basic.c] It should work properly ... ");
    napc_mute();
	napc_u8 iv[16] = {
		1, 2, 3, 4, 5, 6, 7, 8,
		1, 2, 3, 4, 5, 6, 7, 8
	};
	napc_u8 data[16] = {
		'h', 'e', 'l', 'l', 'o', ' ',
		'w', 'o', 'r', 'l', 'd', '!', 0,
		// filler
		0xee, 0xee, 0xee
	};

	const napc_u8 expected_cipher[16] = {
		0xbc,0xe9,0xce,0xc3,0xb3,0xcb,0x53,0x7d,0xd7,0xcd,0xfd,0xd6,0xd8,0xbd,0xa6,0x57
	};

	const napc_u8 expected_plain[16] = {
		'h', 'e', 'l', 'l', 'o', ' ',
		'w', 'o', 'r', 'l', 'd', '!', 0,
		// filler
		0xee, 0xee, 0xee
	};

	// key is SHA256(test)
	const char *key = "9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08";

	TEST_ASSERT(
		napc_aes_encrypt(iv, key, data, sizeof(data))
	);

	TEST_ASSERT(
		memcmp(data, expected_cipher, sizeof(data)) == 0
	);

	TEST_ASSERT(
		napc_aes_decrypt(iv, key, data, sizeof(data))
	);

	TEST_ASSERT(
		memcmp(data, expected_plain, sizeof(data)) == 0
	);
}
