#include <napc.h>
#include <napc-testing.h>

struct test_element {
	char str[45];
	unsigned long value1;
};

TEST_CASE("should work properly") {
	struct test_element array[4];

	strncpy(array[0].str, "str at index 0", sizeof(array[0].str));
	strncpy(array[1].str, "str at index 1", sizeof(array[1].str));
	strncpy(array[2].str, "str at index 2", sizeof(array[2].str));
	strncpy(array[3].str, "str at index 3", sizeof(array[3].str));
	array[0].value1 = 0x01abul;
	array[1].value1 = 0x02deul;
	array[2].value1 = 0x03ceul;
	array[3].value1 = 0x04eeul;

	napc_misc_shiftArrayRight(array, 4, sizeof(struct test_element));

	TEST_ASSERT(
		strcmp(array[1].str, "str at index 0") == 0
	);
	TEST_ASSERT(
		strcmp(array[2].str, "str at index 1") == 0
	);
	TEST_ASSERT(
		strcmp(array[3].str, "str at index 2") == 0
	);
	TEST_ASSERT(array[1].value1 == 0x01abul);
	TEST_ASSERT(array[2].value1 == 0x02deul);
	TEST_ASSERT(array[3].value1 == 0x03ceul);
}
