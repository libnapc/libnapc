#include <module/pool/_private/_pool.h>

void libnapc_Pool_releaseElement(
	libnapc__Pool *pool,
	libnapc_size element_index
) {
	LIBNAPC_MAGIC_ASSERT(napc__Pool, pool);

	if (!pool->elements_used[element_index]) {
		LIBNAPC_PANIC(
			"Trying to release an element (index=%" LIBNAPC_SIZE_PRINT_DEC ") that has already been freed!",
			element_index
		);
	}

	pool->elements_used[element_index] = false;
}
