#include <module/pool/_private/_pool.h>

bool libnapc_Pool_isClaimed(
	const libnapc__Pool *pool,
	libnapc_size element_index
) {
	LIBNAPC_MAGIC_ASSERT(napc__Pool, pool);

	if (element_index > pool->num_elements) {
		LIBNAPC_PANIC("Element index is out of range. (pool=%s)", pool->label);
	}

	return pool->elements_used[element_index];
}
