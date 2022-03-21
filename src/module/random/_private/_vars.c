#include <module/random/_private/_random.h>

napc_u8 PV_napc_used_random_bytes[PV_NAPC_RAND_POOL_SIZE / 8]; // @global
napc_u8 PV_napc_random_bytes_pool[PV_NAPC_RAND_POOL_SIZE]; // @global
