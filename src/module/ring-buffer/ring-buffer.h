/*!
 * @name RingBuffer:intro
 * @brief Circular byte buffer
 */
#if !defined(NAPC_MODULE_RINGBUFFER_h)
	#define NAPC_MODULE_RINGBUFFER_h

	#include <libnapc.h>
	#include <napc-magic/napc-magic.h>
	#include <napc-core/napc-core.h> // napc__AccessFailureMode

	/*!
	 * @name napc__RingBuffer
	 * @module RingBuffer
	 * @brief Representation of a RingBuffer.
	 * @version 2.0.0
	 * @opaque
	 * @changelog 2.0.0 21.10.2022 initial version
	 */
	typedef struct napc__RingBuffer {
		NAPC_MAGIC_MEMBER;

		napc__AccessFailureMode _fail_mode;

		napc_u8 *buffer;
		napc_size buffer_size;

		napc_size read_position;
		napc_size write_position;

		bool buffer_full;
	} napc__RingBuffer;

	/*!
	 * @name napc_RingBuffer_init
	 * @brief Initialize a RingBuffer.
	 * @version 2.0.0
	 * @description
	 * Initializes a circular buffer object.
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param buffer Pointer to the buffer to be used.
	 * @param buffer_size Size of the buffer `buffer`.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @example
	 * napc__RingBuffer rbuffer;
	 * napc_u8 buffer[512];
	 * 
	 * napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer));
	 */
	void napc_RingBuffer_init(
		napc__RingBuffer *ctx, napc_u8 *buffer, napc_size buffer_size
	);

	/*!
	 * @name napc_RingBuffer_create
	 * @brief Create a RingBuffer object.
	 * @version 2.0.0
	 * @param buffer Pointer to the buffer to be used.
	 * @param buffer_size Size of the buffer `buffer`.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @example
	 * napc_u8 buffer[512];
	 * 
	 * napc__RingBuffer rbuffer = napc_RingBuffer_create(buffer, sizeof(buffer));
	 */
	napc__RingBuffer napc_RingBuffer_create(napc_u8 *buffer, napc_size buffer_size);

	/*!
	 * @name napc_RingBuffer_setAccessFailureMode
	 * @brief Set action to be taken on access failure.
	 * @version 2.0.0.
	 * @description
	 * Sets the action to be taken when `insertByte`, `peekByte` or `removeByte` fail (i.e. return `false`).
	 * 
	 * The default is to log an error message but can be overwritten by `napc_setDefaultAccessFailureMode`.
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param mode The fail mode to set.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @notes
	 * For more information refer to the `napc__AccessFailureMode` type.
	 */
	void napc_RingBuffer_setAccessFailureMode(
		napc__RingBuffer *ctx, napc__AccessFailureMode mode
	);

	/*!
	 * @name napc_RingBuffer_getBufferSize
	 * @brief Get buffer size.
	 * @description
	 * Gets the size of the underlying buffer used to store the data.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @example
	 * napc_u8 buffer[512];
	 * 
	 * napc__RingBuffer rbuffer = napc_RingBuffer_create(buffer, sizeof(buffer));
	 * 
	 * napc_size size = napc_RingBuffer_getBufferSize(&rbuffer); // size will be 512
	 */
	napc_size napc_RingBuffer_getBufferSize(const napc__RingBuffer *ctx);

	/*!
	 * @name napc_RingBuffer_getAvailableBytes
	 * @brief Get number of bytes available for reading.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @return
	 * Returns the number of bytes that can be read immediately.
	 */
	napc_size napc_RingBuffer_getAvailableBytes(const napc__RingBuffer *ctx);

	/*!
	 * @name napc_RingBuffer_peekByte
	 * @brief Attempt to read a byte without removing it.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param out Variable to store read byte.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @return
	 * Returns `true` if the byte at the current read position could be read.
	 * @warning
	 * `out` remains UNMODIFIED if function returned false.
	 */
	bool napc_RingBuffer_peekByte(const napc__RingBuffer *ctx, napc_u8 *out);

	/*!
	 * @name napc_RingBuffer_removeByte
	 * @brief Attempt to read a byte.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param out Variable to store read byte.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @return
	 * Returns `true` if the byte at the current read position could be read.
	 * @warning
	 * `out` remains UNMODIFIED if function returned false.
	 */
	bool napc_RingBuffer_removeByte(napc__RingBuffer *ctx, napc_u8 *out);

	/*!
	 * @name napc_RingBuffer_insertByte
	 * @brief Attempt to insert a byte.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param byte Byte to store in circular buffer.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @return
	 * Returns `true` if the byte at the current write position could be written.
	 * @warning
	 * If the buffer is full the byte `byte` will not be inserted and `false` is returned.
	 */
	bool napc_RingBuffer_insertByte(napc__RingBuffer *ctx, napc_u8 byte);

	/*!
	 * @name napc_RingBuffer_forceInsertByte
	 * @brief Insert a byte.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param byte Byte to store in circular buffer.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @warning
	 * If the buffer is full the byte `byte` will be forcefully inserted.
	 */
	void napc_RingBuffer_forceInsertByte(napc__RingBuffer *ctx, napc_u8 byte);

	/*!
	 * @name napc_RingBuffer_reset
	 * @brief Reset buffer.
	 * @version 2.0.0
	 * @description
	 * Resets the write and read position of a buffer.
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @notes
	 * This does not clear the data in the underlying buffer.
	 * 
	 * Only the write and read positions are reset.
	 */
	void napc_RingBuffer_reset(napc__RingBuffer *ctx);
#endif
