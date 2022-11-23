#include <module/pool/_private/_pool.h>

bool napc_Pool_isAllocated(
	const napc__Pool *pool,
	libnapc_size element_index
) {
	return napc_Pool_isClaimed(pool, element_index);
}
