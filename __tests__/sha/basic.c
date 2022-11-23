#include <libnapc.h>
#include <libnapc-testing.h>

TEST_CASE("It should work properly") {
	char out[65];
	const char *str = "secret_string";

	NAPC_ASSERT(
		napc_sha_calculate(str, napc_strlen(str), out, sizeof(out))
	);

	NAPC_ASSERT(
		memcmp(
			out,
			"850f9c6966cc780194218689986e2f8635764196f5a78b8021566a7a3bddbbcc\x00",
			65
		) == 0
	);
}

TEST_CASE("It should work with empty string") {
	char out[65];
	const char *str = "";

	NAPC_ASSERT(
		napc_sha_calculate(str, napc_strlen(str), out, sizeof(out))
	);

	NAPC_ASSERT(
		memcmp(
			out,
			"e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855\x00",
			65
		) == 0
	);
}

TEST_CASE("It should fail with a too small output buffer") {
	char out[64];
	const char *str = "";

	NAPC_ASSERT(
		!napc_sha_calculate(str, napc_strlen(str), out, sizeof(out))
	);
}
