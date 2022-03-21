#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_misc__testCase9(void) {
    napc_unmute();
    napc_puts("[misc/memory_fence.c] should work properly ... ");
    napc_mute();
	// memory fence of 16 bytes each
	napc_size buffer_size = 2048 + 16 + 16;
	unsigned char *buffer = malloc(buffer_size);
	memset(buffer, 0xBB, buffer_size);

	napc_misc_setMemoryFenceBytes(buffer, buffer_size, 16, 0xAA);

	TEST_ASSERT(buffer[0] == 0xAA);
	TEST_ASSERT(buffer[15] == 0xAA);
	TEST_ASSERT(buffer[16] == 0xBB);

	TEST_ASSERT(buffer[2063] == 0xBB);
	TEST_ASSERT(buffer[2064] == 0xAA);

	TEST_ASSERT(napc_misc_verifyMemoryFenceBytes(buffer, buffer_size, 16, 0xAA));
	buffer[2064] = 0x0;
	TEST_ASSERT(!napc_misc_verifyMemoryFenceBytes(buffer, buffer_size, 16, 0xAA));
	buffer[2064] = 0xAA;
	TEST_ASSERT(napc_misc_verifyMemoryFenceBytes(buffer, buffer_size, 16, 0xAA));
	buffer[15] = 0x0;
	TEST_ASSERT(!napc_misc_verifyMemoryFenceBytes(buffer, buffer_size, 16, 0xAA));
	free(buffer);
}
