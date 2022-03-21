#if !defined(HAL_NAPC_RAND_h)
	#define HAL_NAPC_RAND_h

	#include <napc-rand-source/napc-rand-source.h>

	void HAL_napc_initRandomBitSources(void);

	const int *HAL_napc_getRandomBitSources(void);

	bool HAL_napc_getRandomBit(bool *out, int source);
#endif
