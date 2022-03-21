#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_writer__testCase86(void) {
    napc_unmute();
    napc_puts("[writer/u16be.c] should write u16be correctly ... ");
    napc_mute();
	napc_u8 data[5] = {0, 0, 0, 0, 0};
	napc__Writer ctx;

	napc_Writer_init(&ctx, data, sizeof(data));

	TEST_ASSERT(napc_Writer_writeU16BE(&ctx, NAPC_U16_LITERAL(0xabde)));
	TEST_ASSERT(napc_Writer_writeU16BE(&ctx, NAPC_U16_LITERAL(0xcdef)));
	TEST_ASSERT(!napc_Writer_writeU16BE(&ctx, NAPC_U16_LITERAL(0xff00)));

	TEST_ASSERT(memcmp(data, "\xab\xde\xcd\xef", 5) == 0);
}
