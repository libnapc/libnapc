/* <-- add '!' back once ported -->
 * @name Pool:intro
 * @brief Static memory allocation
 */
#if !defined(LIBNAPC_MODULE_POOL_h)
	#define LIBNAPC_MODULE_POOL_h

	#include <libnapc-internal.h>
	#include <libnapc-magic/libnapc-magic.h>

	#define LIBNAPC_POOL_MAX 32

	/*!
	 * @module Pool
	 * @type type:opaque
	 * @fullname libnapc__Pool
	 * @brief Represenation of a fixed memory pool.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	typedef struct libnapc__Pool {
		LIBNAPC_MAGIC_MEMBER;

		const char *label;

		unsigned char *array_start;
		bool elements_used[LIBNAPC_POOL_MAX];

		libnapc_size num_elements;
		libnapc_size element_size;
	} libnapc__Pool;

	/*!
	 * Initializes a static (fixed sized) pool.
	 * 
	 * @module Pool
	 * @type fn
	 * @fullname libnapc_Pool_init
	 * @name init
	 * @brief Initialize a static pool.
	 * @version 2.0.0
	 * @param pool Pointer to the instance.
	 * @param pool_label Label for pool. (must be a constant)
	 * @param array_start Start address of array (to be used by the pool)
	 * @param num_elements Number of elements in array.
	 * @param element_size Size (in bytes) of a single element in the array.
	 * @changelog 2.0.0 initial version
	 * @example
	 * int buffer[5];
	 * libnapc__Pool pool;
	 * 
	 * libnapc_Pool_init(&pool, "int pool", buffer, 5, sizeof(int));
	 * 
	 * libnapc_ssize id = libnapc_Pool_claimElement(&pool);
	 * 
	 * int *first_element = libnapc_Pool_getAddress(&pool, id);
	 */
	void libnapc_Pool_init(
		libnapc__Pool *pool,
		const char *pool_label,
		void *array_start,
		libnapc_size num_elements,
		libnapc_size element_size
	);

	/*!
	 * Allocates an element from the pool `pool`.
	 * 
	 * @module Pool
	 * @type fn
	 * @fullname libnapc_Pool_claimElement
	 * @name claimElement
	 * @brief Claim an element of a pool.
	 * @version 2.0.0
	 * @param pool Pointer to `libnapc__Pool` instance.
	 * @warning
	 * If the pool is exhausted program execution is halted.
	 * @changelog 2.0.0 initial version
	 */
	libnapc_ssize libnapc_Pool_claimElement(
		libnapc__Pool *pool
	);

	/*!
	 * Checks if a particular element is allocated (in use) or not.
	 * 
	 * @module Pool
	 * @type fn
	 * @fullname libnapc_Pool_isClaimed
	 * @name isClaimed
	 * @brief Check if element is claimed.
	 * @version 2.0.0
	 * @param pool Pointer to `libnapc__Pool` instance.
	 * @param element_index Index of element to check.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_Pool_isClaimed(
		const libnapc__Pool *pool,
		libnapc_size element_index
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Gets the number of available elements in the pool.
	 * 
	 * @module Pool
	 * @type fn
	 * @fullname libnapc_Pool_getAvailable
	 * @name getAvailable
	 * @brief Get available elements.
	 * @version 2.0.0
	 * @param pool Pointer to `libnapc__Pool` instance.
	 * @return Returns the number of available elements in the pool.
	 * @changelog 2.0.0 initial version
	 */
	libnapc_size libnapc_Pool_getAvailable(
		const libnapc__Pool *pool
	);

	/*!
	 * Gets the address of an allocated element in the pool.
	 * 
	 * @module Pool
	 * @type fn
	 * @fullname libnapc_Pool_getAddress
	 * @name getAddress
	 * @brief Get address of an element.
	 * @version 2.0.0
	 * @param pool Pointer to `libnapc__Pool` instance.
	 * @param element_index Index of element.
	 * @return The element's address.
	 * @warning
	 * This function can only be used to get the address of allocated elements in the pool.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * int buffer[5];
	 * libnapc__Pool pool;
	 * 
	 * libnapc_Pool_init(&pool, "int pool", buffer, 5, sizeof(int));
	 * 
	 * libnapc_ssize id = libnapc_Pool_claimElement(&pool);
	 * 
	 * int *first_element = libnapc_Pool_getAddress(&pool, id);
	 */
	void *libnapc_Pool_getAddress(
		const libnapc__Pool *pool,
		libnapc_size element_index
	);

	/*!
	 * Releases an element from the pool.
	 * 
	 * @module Pool
	 * @type fn
	 * @fullname libnapc_Pool_releaseElement
	 * @name releaseElement
	 * @brief Release an element.
	 * @version 2.0.0
	 * @param pool Pointer to `libnapc__Pool` instance.
	 * @param element_index Index of element.
	 * @changelog 2.0.0 initial version
	 */
	void libnapc_Pool_releaseElement(
		libnapc__Pool *pool,
		libnapc_size element_index
	);
#endif
