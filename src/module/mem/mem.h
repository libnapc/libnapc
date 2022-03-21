#if !defined(NAPC_MODULE_MEM_h)
	#define NAPC_MODULE_MEM_h

	#include <libnapc.h>

	#include <module/buffer/buffer.h>

	/*!
	 * @name napc_mem_registerSharedBuffer
	 * @version 1.0.0
	 * @description
	 * Registers a global shared buffer.
	 * @param label Label of shared buffer.
	 * @param buffer Buffer start address.
	 * @param buffer_size Size of `buffer`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void napc_mem_registerSharedBuffer(
		const char *label, void *buffer, napc_size buffer_size
	);

	/*!
	 * @name napc_mem_claimSharedBuffer
	 * @version 1.0.0
	 * @description
	 * Claim the shared buffer `label` making it unavailable to other callers until
	 * it is released.
	 * @param label The shared buffer to be claimed.
	 * @param out `napc__Buffer` object to place buffer address and size in.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void napc_mem_claimSharedBuffer(
		const char *label, napc__Buffer **out
	);

	/*!
	 * @name napc_mem_releaseSharedBuffer
	 * @version 1.0.0
	 * @description
	 * Release a shared buffer making it available for others again.
	 * @param buffer The buffer to be released.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void napc_mem_releaseSharedBuffer(
		napc__Buffer *buffer
	);
#endif
