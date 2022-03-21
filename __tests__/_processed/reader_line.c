#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

void PV_napc_reader__testCase73(void) {
    napc_unmute();
    napc_puts("[reader/line.c] It should work properly ... ");
    napc_mute();
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

void PV_napc_reader__testCase74(void) {
    napc_unmute();
    napc_puts("[reader/line.c] It should work with a string that does not end with a new line ... ");
    napc_mute();
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

void PV_napc_reader__testCase75(void) {
    napc_unmute();
    napc_puts("[reader/line.c] It should truncate properly ... ");
    napc_mute();
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

void PV_napc_reader__testCase76(void) {
    napc_unmute();
    napc_puts("[reader/line.c] It should work with empty lines in between (bug #1) ... ");
    napc_mute();
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
