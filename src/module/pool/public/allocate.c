#include <module/pool/_private/_pool.h>

napc_ssize napc_Pool_allocate(
	napc__Pool *pool
) {
	return napc_Pool_claimElement(pool);
}
