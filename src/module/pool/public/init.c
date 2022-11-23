#include <module/pool/_private/_pool.h>

void napc_Pool_init(
	napc__Pool *pool,
	const char *pool_label,
	void *array_start,
	napc_size num_elements,
	napc_size element_size
) {
	if (num_elements > NAPC_POOL_MAX) {
		LIBNAPC_PANIC("Too many entries for pool.");
	}

	pool->label        = !pool_label ? "(null)" : pool_label;
	pool->num_elements = num_elements;
	pool->element_size = element_size;
	pool->array_start  = array_start;

	for (napc_size i = 0; i < NAPC_POOL_MAX; ++i) {
		pool->elements_used[i] = false;
	}

	NAPC_MAGIC_INIT(napc__Pool, pool);
}
