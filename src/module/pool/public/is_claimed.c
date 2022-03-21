#include <module/pool/_private/_pool.h>

bool napc_Pool_isClaimed(
	const napc__Pool *pool,
	napc_size element_index
) {
	NAPC_MAGIC_ASSERT(napc__Pool, pool);

	if (element_index > pool->num_elements) {
		NAPC_PANIC("Element index is out of range. (pool=%s)", pool->label);
	}

	return pool->elements_used[element_index];
}
