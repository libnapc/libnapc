#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should read chars correctly") {
	char data[3] = {'a', 'b', 'c'};
	libnapc__Reader ctx;

	libnapc_Reader_init(&ctx, data, sizeof(data));

	char tmp = 0;
	TEST_ASSERT(libnapc_Reader_readChar(&ctx, &tmp));
	TEST_ASSERT(tmp == 'a');
	TEST_ASSERT(libnapc_Reader_readChar(&ctx, &tmp));
	TEST_ASSERT(tmp == 'b');
	TEST_ASSERT(libnapc_Reader_readChar(&ctx, &tmp));
	TEST_ASSERT(tmp == 'c');
	TEST_ASSERT(!libnapc_Reader_readChar(&ctx, &tmp));
}

TEST_CASE("should read chars correctly with out=NULL") {
	char data[3] = {'a', 'b', 'c'};
	libnapc__Reader ctx;

	libnapc_Reader_init(&ctx, data, sizeof(data));

	TEST_ASSERT(libnapc_Reader_readChar(&ctx, NULL));
	TEST_ASSERT(libnapc_Reader_readChar(&ctx, NULL));
	char tmp = 0;
	TEST_ASSERT(libnapc_Reader_readChar(&ctx, &tmp));
	TEST_ASSERT(tmp == 'c');
	TEST_ASSERT(!libnapc_Reader_readChar(&ctx, NULL));
}

/*
SKIP_TEST_CASE("should work correctly with a size of 0") {
	char data[3] = {'a', 'b', 'c'};
	libnapc__Reader ctx;

	libnapc_Reader_init(&ctx, data, 0);


	TEST_ASSERT(!libnapc_Reader_readChar(&ctx, NULL));
}
*/
