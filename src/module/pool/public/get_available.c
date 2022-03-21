#include <module/pool/_private/_pool.h>

napc_size napc_Pool_getAvailable(
	const napc__Pool *pool
) {
	NAPC_MAGIC_ASSERT(napc__Pool, pool);

	napc_size count = 0;

	for (napc_size i = 0; i < pool->num_elements; ++i) {
		if (!pool->elements_used[i]) {
			++count;
		}
	}

	return count;
}
