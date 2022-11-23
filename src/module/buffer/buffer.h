/*!
 * @name Buffer:intro
 * @description
 * To reduce parameter count this module is used to pass a buffer with its size to a function:
 * 
 * ```c
 * char data[512];
 * napc__Buffer buffer;
 * 
 * napc_Buffer_init(&buffer, data, sizeof(data));
 * ```
 */
#if !defined(NAPC_MODULE_BUFFER_h)
	#define NAPC_MODULE_BUFFER_h

	#include <libnapc-internal.h>

	#include <napc-magic/napc-magic.h>

	/*!
	 * @name napc__Buffer
	 * @module Buffer
	 * @brief Representation of a memory buffer.
	 * @version 1.0.0
	 * @field size Size of data.
	 * @field data Pointer to data.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct napc__Buffer {
		NAPC_MAGIC_MEMBER; // used to detect uninitialized buffers

		napc_size size;
		void *data;
	} napc__Buffer;

	/*!
	 * @name napc_Buffer_init
	 * @brief Initialize a buffer.
	 * @version 1.0.0
	 * @description
	 * Initialize a buffer.
	 * @param buffer Pointer to napc__Buffer instance to be initialized.
	 * @param data Pointer to data.
	 * @param data_size Size of data.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char message[512];
	 * napc__Buffer buffer;
	 * 
	 * napc_Buffer_init(&buffer, message, sizeof(message));
	 */
	void napc_Buffer_init(
		napc__Buffer *buffer, void *data, napc_size data_size
	);

	/*!
	 * @name napc_Buffer_create
	 * @brief Create a buffer.
	 * @version 1.0.0
	 * @description
	 * Create a buffer.
	 * @param data Pointer to data.
	 * @param data_size Size of data.
	 * @return Returns an initialized buffer.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char message[512];
	 * 
	 * napc__Buffer buffer = napc_Buffer_create(message, sizeof(message));
	 */
	napc__Buffer napc_Buffer_create(void *data, napc_size data_size);
#endif
