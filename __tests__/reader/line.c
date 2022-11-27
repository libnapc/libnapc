#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("It should work properly") {
	const char *input = "hello\nworld\n";
	char line[128];
	libnapc__Reader ctx;
	libnapc_Reader_init(&ctx, input, strlen(input));

	TEST_ASSERT(
		strcmp(
			"hello",
			libnapc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(
		strcmp(
			"world",
			libnapc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(!libnapc_Reader_readLine(&ctx, line, sizeof(line)));
}

TEST_CASE("It should work with a string that does not end with a new line") {
	const char *input = "hello\nabc";
	char line[128];
	libnapc__Reader ctx;
	libnapc_Reader_init(&ctx, input, strlen(input));

	TEST_ASSERT(
		strcmp(
			"hello",
			libnapc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(
		strcmp(
			"abc",
			libnapc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(!libnapc_Reader_readLine(&ctx, line, sizeof(line)));
}

TEST_CASE("It should truncate properly") {
	const char *input = "hello\nworld";
	char line[3];
	libnapc__Reader ctx;
	libnapc_Reader_init(&ctx, input, strlen(input));

	TEST_ASSERT(
		strcmp(
			"he",
			libnapc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(
		strcmp(
			"wo",
			libnapc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(!libnapc_Reader_readLine(&ctx, line, sizeof(line)));
}

TEST_CASE("It should work with empty lines in between (bug #1)") {
	const char *input = "hello\n\n\nworld";
	char line[128];
	libnapc__Reader ctx;
	libnapc_Reader_init(&ctx, input, strlen(input));

	TEST_ASSERT(
		strcmp(
			"hello",
			libnapc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);
	TEST_ASSERT(!strlen(libnapc_Reader_readLine(&ctx, line, sizeof(line))));
	TEST_ASSERT(!strlen(libnapc_Reader_readLine(&ctx, line, sizeof(line))));
	TEST_ASSERT(
		strcmp(
			"world",
			libnapc_Reader_readLine(&ctx, line, sizeof(line))
		) == 0
	);

	TEST_ASSERT(!libnapc_Reader_readLine(&ctx, line, sizeof(line)));
}
