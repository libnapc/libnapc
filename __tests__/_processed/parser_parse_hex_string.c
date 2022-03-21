#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_parser__testCase25(void) {
    napc_unmute();
    napc_puts("[parser/parse_hex_string.c] It should work properly ... ");
    napc_mute();
	napc_u8 out[16];

	TEST_ASSERT(
		napc_parser_parseHexString("1e49863fc6ac554156095950f49098b4", 16, out)
	);

	const napc_u8 expected[16] = {
		0x1e,0x49,0x86,0x3f,0xc6,0xac,0x55,0x41,0x56,0x09,0x59,0x50,0xf4,0x90,0x98,0xb4
	};

	for (napc_size i = 0; i < 16; ++i) {
		TEST_ASSERT(out[i] == expected[i]);
	}
}
