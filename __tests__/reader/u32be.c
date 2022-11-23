#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("should read u32be correctly") {
	libnapc_u8 data[10] = {
		0xa, 0xb, 0xc, 0xd,
		0xe, 0xf, 0x1, 0x2,
		0xa, 0xb
	};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	libnapc_u32 tmp = 0;
	TEST_ASSERT(napc_Reader_readU32BE(&ctx, &tmp));
	TEST_ASSERT(tmp == LIBNAPC_U32_LITERAL(0x0a0b0c0d));
	TEST_ASSERT(napc_Reader_readU32BE(&ctx, &tmp));
	TEST_ASSERT(tmp == LIBNAPC_U32_LITERAL(0x0e0f0102));
	TEST_ASSERT(!napc_Reader_readU32BE(&ctx, &tmp));
}

TEST_CASE("should read u32be correctly with out=NULL") {
	libnapc_u8 data[10] = {
		0xa, 0xb, 0xc, 0xd,
		0xe, 0xf, 0x1, 0x2,
		0xa, 0xb
	};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, sizeof(data));

	TEST_ASSERT(napc_Reader_readU32BE(&ctx, NULL));
	libnapc_u32 tmp = 0;
	TEST_ASSERT(napc_Reader_readU32BE(&ctx, &tmp));
	TEST_ASSERT(tmp == LIBNAPC_U32_LITERAL(0x0e0f0102));
	TEST_ASSERT(!napc_Reader_readU32BE(&ctx, NULL));
}

/*
SKIP_TEST_CASE("should work correctly with a size of 0") {
	libnapc_u8 data[5] = {0xa, 0xb, 0xc, 0xd, 0xe};
	napc__Reader ctx;

	napc_Reader_init(&ctx, data, 0);

	TEST_ASSERT(!napc_Reader_readU32BE(&ctx, NULL));
}
*/
