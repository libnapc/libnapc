#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_reader__testCase71(void) {
    napc_unmute();
    napc_puts("[reader/char.c] should read chars correctly ... ");
    napc_mute();
	char data[3] = {'a', 'b', 'c'};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	char tmp = 0;
	TEST_ASSERT(napc_Reader_readChar(&ctx, &tmp));
	TEST_ASSERT(tmp == 'a');
	TEST_ASSERT(napc_Reader_readChar(&ctx, &tmp));
	TEST_ASSERT(tmp == 'b');
	TEST_ASSERT(napc_Reader_readChar(&ctx, &tmp));
	TEST_ASSERT(tmp == 'c');
	TEST_ASSERT(!napc_Reader_readChar(&ctx, &tmp));
}

void PV_napc_reader__testCase72(void) {
    napc_unmute();
    napc_puts("[reader/char.c] should read chars correctly with out=NULL ... ");
    napc_mute();
	char data[3] = {'a', 'b', 'c'};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	TEST_ASSERT(napc_Reader_readChar(&ctx, NULL));
	TEST_ASSERT(napc_Reader_readChar(&ctx, NULL));
	char tmp = 0;
	TEST_ASSERT(napc_Reader_readChar(&ctx, &tmp));
	TEST_ASSERT(tmp == 'c');
	TEST_ASSERT(!napc_Reader_readChar(&ctx, NULL));
}

/*
SKIP_TEST_CASE("should work correctly with a size of 0") {
	char data[3] = {'a', 'b', 'c'};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, 0);


	TEST_ASSERT(!napc_Reader_readChar(&ctx, NULL));
}
*/
