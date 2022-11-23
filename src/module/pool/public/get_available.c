#include <module/pool/_private/_pool.h>

libnapc_size napc_Pool_getAvailable(
	const napc__Pool *pool
) {
	NAPC_MAGIC_ASSERT(napc__Pool, pool);

	libnapc_size count = 0;

	for (libnapc_size i = 0; i < pool->num_elements; ++i) {
		if (!pool->elements_used[i]) {
			++count;
		}
	}

	return count;
}
