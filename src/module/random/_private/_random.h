#if !defined(PV_NAPC_MODULE_RANDOM_h)
	#define PV_NAPC_MODULE_RANDOM_h

	#include <module/random/random.h>

	#include <napc-rand-source/napc-rand-source.h> // napc_getRandomByte()
	#include <napc-delay/napc-delay.h> // napc_delayUs()

	#define PV_NAPC_RAND_POOL_SIZE 1024u

	void PV_napc_random_initPool(void);

	bool PV_napc_random_getByteUsed(napc_size byte_index);
	void PV_napc_random_setByteUsed(napc_size byte_index, bool used);

	napc_u8 PV_napc_random_consumeByte(void);

	extern napc_u8 PV_napc_used_random_bytes[PV_NAPC_RAND_POOL_SIZE / 8]; // @global
	extern napc_u8 PV_napc_random_bytes_pool[PV_NAPC_RAND_POOL_SIZE]; // @global
#endif
