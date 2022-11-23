#include <module/pool/_private/_pool.h>

libnapc_ssize napc_Pool_claimElement(
	napc__Pool *pool
) {
	NAPC_MAGIC_ASSERT(napc__Pool, pool);

	for (libnapc_size i = 0; i < pool->num_elements; ++i) {
		if (!pool->elements_used[i]) {
			pool->elements_used[i] = true;

			return i;
		}
	}

	LIBNAPC_PANIC(
		"Cannot allocate element: pool is out of memory. (pool=%s)",
		pool->label
	);

	return -1;
}
