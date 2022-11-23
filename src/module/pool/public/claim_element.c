#include <module/pool/_private/_pool.h>

napc_ssize napc_Pool_claimElement(
	napc__Pool *pool
) {
	NAPC_MAGIC_ASSERT(napc__Pool, pool);

	for (napc_size i = 0; i < pool->num_elements; ++i) {
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
