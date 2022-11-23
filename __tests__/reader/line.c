#include <napc.h>
#include <libnapc-testing.h>

TEST_CASE("It should work properly") {
	const char *input = "hello\nworld\n";
	char line[128];
	napc__Reader ctx;
	napc_Reader_init(&ctx, input, strlen(input));

	TEST_ASSERT(
		strcmp(
			"hello",
			napc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(
		strcmp(
			"world",
			napc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(!napc_Reader_readLine(&ctx, line, sizeof(line)));
}

TEST_CASE("It should work with a string that does not end with a new line") {
	const char *input = "hello\nabc";
	char line[128];
	napc__Reader ctx;
	napc_Reader_init(&ctx, input, strlen(input));

	TEST_ASSERT(
		strcmp(
			"hello",
			napc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(
		strcmp(
			"abc",
			napc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(!napc_Reader_readLine(&ctx, line, sizeof(line)));
}

TEST_CASE("It should truncate properly") {
	const char *input = "hello\nworld";
	char line[3];
	napc__Reader ctx;
	napc_Reader_init(&ctx, input, strlen(input));

	TEST_ASSERT(
		strcmp(
			"he",
			napc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(
		strcmp(
			"wo",
			napc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(!napc_Reader_readLine(&ctx, line, sizeof(line)));
}

TEST_CASE("It should work with empty lines in between (bug #1)") {
	const char *input = "hello\n\n\nworld";
	char line[128];
	napc__Reader ctx;
	napc_Reader_init(&ctx, input, strlen(input));

	TEST_ASSERT(
		strcmp(
			"hello",
			napc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(!strlen(napc_Reader_readLine(&ctx, line, sizeof(line))));
	TEST_ASSERT(!strlen(napc_Reader_readLine(&ctx, line, sizeof(line))));
	TEST_ASSERT(
		strcmp(
			"world",
			napc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);

	TEST_ASSERT(!napc_Reader_readLine(&ctx, line, sizeof(line)));
}
