#include <module/pool/_private/_pool.h>

libnapc_size libnapc_Pool_getAvailable(
	const libnapc__Pool *pool
) {
	LIBNAPC_MAGIC_ASSERT(napc__Pool, pool);

	libnapc_size count = 0;

	for (libnapc_size i = 0; i < pool->num_elements; ++i) {
		if (!pool->elements_used[i]) {
			++count;
		}
	}

	return count;
}
