#include <module/pool/_private/_pool.h>

void napc_Pool_release(
	napc__Pool *pool,
	libnapc_size element_index
) {
	napc_Pool_releaseElement(pool, element_index);
}
