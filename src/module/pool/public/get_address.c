#include <module/pool/_private/_pool.h>

void *libnapc_Pool_getAddress(
	const libnapc__Pool *pool,
	libnapc_size element_index
) {
	LIBNAPC_MAGIC_ASSERT(napc__Pool, pool);

	if (element_index > pool->num_elements) {
		LIBNAPC_PANIC("Element index is out of range. (pool=%s)", pool->label);
	} else if (!pool->elements_used[element_index]) {
		LIBNAPC_PANIC(
			"Cannot get address of element (index=%" LIBNAPC_SIZE_PRINT_DEC ")"
			" that is not allocated (pool=%s).",
			element_index, pool->label
		);
	}

	unsigned char *base = pool->array_start;

	base += (pool->element_size * element_index);

	return (void *)base;
}
