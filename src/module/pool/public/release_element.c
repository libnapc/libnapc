#include <module/pool/_private/_pool.h>

void napc_Pool_releaseElement(
	napc__Pool *pool,
	libnapc_size element_index
) {
	NAPC_MAGIC_ASSERT(napc__Pool, pool);

	if (!pool->elements_used[element_index]) {
		LIBNAPC_PANIC(
			"Trying to release an element (index=%" LIBNAPC_SIZE_PRINT_DEC ") that has already been freed!",
			element_index
		);
	}

	pool->elements_used[element_index] = false;
}
