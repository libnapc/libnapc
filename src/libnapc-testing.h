#if !defined(LIBNAPC_TESTING_h)
	#define LIBNAPC_TESTING_h

	#define PV_LIBNAPC_TESTING_CONCAT(a, b) a ## b
	#define LIBNAPC_TESTING_CONCAT(a, b) PV_LIBNAPC_TESTING_CONCAT(a, b)

	#include <string.h>

	/*
	 * This is not the FINAL function name.
	 * It's just here to make clangd happy.
	 */
	#define TEST_CASE(description) \
		LIBNAPC_TESTING_CONCAT(void PV_napc_unitTest, __COUNTER__) (void)

	void PV_libnapc_testAssert(
		const char *assertion,
		const char *file,
		int expr
	);

	#define TEST_ASSERT(expr) \
		PV_libnapc_testAssert(#expr, __FILE__, !!(expr))
#endif
