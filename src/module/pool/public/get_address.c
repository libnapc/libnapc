#include <module/pool/_private/_pool.h>

void *napc_Pool_getAddress(
	const napc__Pool *pool,
	napc_size element_index
) {
	NAPC_MAGIC_ASSERT(napc__Pool, pool);

	if (element_index > pool->num_elements) {
		NAPC_PANIC("Element index is out of range. (pool=%s)", pool->label);
	} else if (!pool->elements_used[element_index]) {
		NAPC_PANIC(
			"Cannot get address of element (index=%" NAPC_SIZE_PRINTF ")"
			" that is not allocated (pool=%s).",
			element_index, pool->label
		);
	}

	unsigned char *base = pool->array_start;

	base += (pool->element_size * element_index);

	return (void *)base;
}
