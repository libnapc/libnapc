#if !defined(LIBNAPC_MODULE_MISC_h)
	#define LIBNAPC_MODULE_MISC_h

	#include <libnapc-internal.h>

	#include <string.h> // memcmp(), memcpy() etc.

	/*!
	 * @module Core
	 * @type fn
	 * @fullname libnapc_misc_printHexArray
	 * @brief Print an array of integers
	 * @version 2.0.0
	 * @param bytes Bytes array.
	 * @param n_bytes Size of bytes array.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 array[4] = {0xde, 0xad, 0xbe, 0xef};
	 * 
	 * // prints deadbeef
	 * libnapc_misc_printHexArray(array, sizeof(array));
	 */
	void libnapc_misc_printHexArray(const void *bytes, libnapc_size n_bytes);

	/*!
	 * Shifts elements in `array` one element to the right discarding the last
	 * element in the array.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname libnapc_misc_shiftArrayRight
	 * @brief Shift elements in an array.
	 * @version 2.0.0
	 * @param array The array to be shifted.
	 * @param n_elements The number of elements in `array`.
	 * @param element_size The size (in bytes) of one element in `array`.
	 * @note
	 * The contents of the first element in `array` will be undefined after this operation.
	 * @changelog 2.0.0 initial version
	 * @example
	 * int data[5] = {1, 2, 3, 4, 5};
	 * 
	 * libnapc_misc_shiftArrayRight(data, 5, sizeof(int));
	 * 
	 * // data[0] is now undefined
	 * // data[1] is now 1
	 * // data[2] is now 2
	 * // data[3] is now 3
	 * // data[4] is now 4
	 */
	void libnapc_misc_shiftArrayRight(
		void *array, libnapc_size n_elements, libnapc_size element_size
	);

	/**************************
	 * Memory fences
	 * To detect buffer over and underflows.
	 */
	void libnapc_misc_setMemoryFenceBytes(
		unsigned char *buffer, libnapc_size buffer_size,
		libnapc_size memory_fence_size, libnapc_u8 fence_value
	);

	bool libnapc_misc_verifyMemoryFenceBytes(
		unsigned char *buffer, libnapc_size buffer_size,
		libnapc_size memory_fence_size, libnapc_u8 fence_value
	);

	/**************************
	 * Chunks
	 */
	typedef libnapc_ssize (*napc_misc_ChunkedOperationCallback)(
		const void *data, libnapc_size data_size, void *context
	);

	/*!
	 * Performs an operation in chunks.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname libnapc_misc_chunkedOperation
	 * @brief Perform an operation in chunks.
	 * @version 2.0.0
	 * @param data Data to process.
	 * @param data_size Size of data to process.
	 * @param chunk_size Size of one chunk.
	 * @param fn Callback for processing one chunk.
	 * @param fn_context Optional context for `fn` callback.
	 * @return Returns `true` on success, `false` otherwise.
	 * @note
	 * `fn` is a function with the following prototype:
	 * 
	 * `libnapc_ssize (const void *data, libnapc_size data_size, void *context)`
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_misc_chunkedOperation(
		const void *data, libnapc_size data_size, libnapc_size chunk_size,
		napc_misc_ChunkedOperationCallback fn, void *fn_context
	) LIBNAPC_FN_WARN_UNUSED_RET();
#endif
