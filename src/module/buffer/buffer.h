/* <-- add '!' back once ported -->
 * @name Buffer:intro
 * @description
 * To reduce parameter count this module is used to pass a buffer with its size to a function:
 * 
 * ```c
 * char data[512];
 * libnapc__Buffer buffer;
 * 
 * libnapc_Buffer_init(&buffer, data, sizeof(data));
 * ```
 */
#if !defined(LIBNAPC_MODULE_BUFFER_h)
	#define LIBNAPC_MODULE_BUFFER_h

	#include <libnapc-internal.h>

	#include <libnapc-magic/libnapc-magic.h>

	/*!
	 * @module Buffer
	 * @type type:struct
	 * @fullname libnapc__Buffer
	 * @brief Representation of a memory buffer.
	 * @version 2.0.0
	 * @field size Size of data.
	 * @field data Pointer to data.
	 * @changelog 2.0.0 initial version
	 */
	typedef struct libnapc__Buffer {
		LIBNAPC_MAGIC_MEMBER_DEFINITION

		libnapc_size size;
		void *data;
	} libnapc__Buffer;

	/*!
	 * @module Buffer
	 * @type fn
	 * @fullname libnapc_Buffer_init
	 * @name init
	 * @brief Initialize a buffer.
	 * @version 2.0.0
	 * @param buffer Pointer to `libnapc__Buffer` instance to be initialized.
	 * @param data Pointer to data.
	 * @param data_size Size of data.
	 * @changelog 2.0.0 initial version
	 * @example
	 * char message[512];
	 * libnapc__Buffer buffer;
	 * 
	 * libnapc_Buffer_init(&buffer, message, sizeof(message));
	 */
	void libnapc_Buffer_init(
		libnapc__Buffer *buffer, void *data, libnapc_size data_size
	);

	/*!
	 * @module Buffer
	 * @type fn
	 * @fullname libnapc_Buffer_create
	 * @name create
	 * @brief Create a buffer.
	 * @version 2.0.0
	 * @param data Pointer to data.
	 * @param data_size Size of data.
	 * @return Returns an initialized buffer.
	 * @changelog 2.0.0 initial version
	 * @example
	 * char message[512];
	 * 
	 * libnapc__Buffer buffer = libnapc_Buffer_create(message, sizeof(message));
	 */
	libnapc__Buffer libnapc_Buffer_create(void *data, libnapc_size data_size);
#endif
