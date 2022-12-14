/* <-- add '!' back once ported -->
 * @name RingBuffer:intro
 * @brief Circular byte buffer
 */
#if !defined(LIBNAPC_MODULE_RINGBUFFER_h)
	#define LIBNAPC_MODULE_RINGBUFFER_h

	#include <libnapc-internal.h>
	#include <libnapc-magic/libnapc-magic.h>
	#include <libnapc-core/libnapc-core.h> // libnapc__AccessFailureMode

	/*!
	 * @module RingBuffer
	 * @type type:opaque
	 * @fullname libnapc__RingBuffer
	 * @brief Representation of a RingBuffer.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	typedef struct libnapc__RingBuffer {
		LIBNAPC_MAGIC_MEMBER_DEFINITION

		libnapc__AccessFailureMode _fail_mode;

		libnapc_u8 *buffer;
		libnapc_size buffer_size;

		libnapc_size read_position;
		libnapc_size write_position;

		bool buffer_full;
	} libnapc__RingBuffer;

	/*!
	 * Initializes a circular buffer object.
	 * 
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_init
	 * @name init
	 * @brief Initialize a RingBuffer.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param buffer Pointer to the buffer to be used.
	 * @param buffer_size Size of the buffer `buffer`.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc__RingBuffer rbuffer;
	 * libnapc_u8 buffer[512];
	 * 
	 * libnapc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer));
	 */
	void libnapc_RingBuffer_init(
		libnapc__RingBuffer *ctx, libnapc_u8 *buffer, libnapc_size buffer_size
	);

	/*!
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_create
	 * @name create
	 * @brief Create a RingBuffer object.
	 * @version 2.0.0
	 * @param buffer Pointer to the buffer to be used.
	 * @param buffer_size Size of the buffer `buffer`.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 buffer[512];
	 * 
	 * libnapc__RingBuffer rbuffer = libnapc_RingBuffer_create(buffer, sizeof(buffer));
	 */
	libnapc__RingBuffer libnapc_RingBuffer_create(libnapc_u8 *buffer, libnapc_size buffer_size);

	/*!
	 * Sets the action to be taken when `insertByte`, `insertBytes`, `peekByte`, `removeByte` or `removeBytes` fail (i.e. return `false`).
	 * 
	 * The default is to log an error message but can be overwritten by `libnapc_setDefaultAccessFailureMode`.
	 * 
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_setAccessFailureMode
	 * @name setAccessFailureMode
	 * @brief Set action to be taken on access failure.
	 * @version 2.0.0.
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param mode The fail mode to set.
	 * @changelog 2.0.0 initial version
	 * @note
	 * For more information refer to the `libnapc__AccessFailureMode` type.
	 */
	void libnapc_RingBuffer_setAccessFailureMode(
		libnapc__RingBuffer *ctx, libnapc__AccessFailureMode mode
	);

	/*!
	 * Gets the size of the underlying buffer used to store the data.
	 * 
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_getBufferSize
	 * @name getBufferSize
	 * @brief Get buffer size.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 buffer[512];
	 * 
	 * libnapc__RingBuffer rbuffer = libnapc_RingBuffer_create(buffer, sizeof(buffer));
	 * 
	 * libnapc_size size = libnapc_RingBuffer_getBufferSize(&rbuffer); // size will be 512
	 */
	libnapc_size libnapc_RingBuffer_getBufferSize(const libnapc__RingBuffer *ctx);

	/*!
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_getAvailableBytes
	 * @name getAvailableBytes
	 * @brief Get number of bytes available for reading.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @changelog 2.0.0 initial version
	 * @return
	 * Returns the number of bytes that can be read immediately.
	 */
	libnapc_size libnapc_RingBuffer_getAvailableBytes(const libnapc__RingBuffer *ctx);

	/*!
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_peekByte
	 * @name peekByte
	 * @brief Attempt to read a byte without removing it.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param out Variable to store read byte.
	 * @changelog 2.0.0 initial version
	 * @return
	 * Returns `true` if the byte at the current read position could be read.
	 * @warning
	 * `out` remains UNMODIFIED if function returned false.
	 */
	bool libnapc_RingBuffer_peekByte(const libnapc__RingBuffer *ctx, libnapc_u8 *out);

	/*!
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_removeByte
	 * @name removeByte
	 * @brief Attempt to read a byte.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param out Variable to store read byte.
	 * @changelog 2.0.0 initial version
	 * @return
	 * Returns `true` if the byte at the current read position could be read.
	 * @warning
	 * `out` remains UNMODIFIED if function returned false.
	 */
	bool libnapc_RingBuffer_removeByte(libnapc__RingBuffer *ctx, libnapc_u8 *out);

	/*!
	 * Attempts to read `out_size` number of bytes from buffer.
	 * 
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_removeBytes
	 * @name removeBytes
	 * @brief Attempt to read an array of bytes.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param out Array to store read bytes from buffer.
	 * @param out_size Size of `out` array.
	 * @changelog 2.0.0 initial version
	 * @return
	 * Returns `true` if number of bytes `out_size` were successfully read from the buffer.
	 * @note
	 * If the buffer has less than `out_size` bytes available to read
	 * then no action is performed and the function returns `false`.
	 */
	bool libnapc_RingBuffer_removeBytes(libnapc__RingBuffer *ctx, libnapc_u8 *out, libnapc_size out_size);

	/*!
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_insertByte
	 * @name insertByte
	 * @brief Attempt to insert a byte.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param byte Byte to store in circular buffer.
	 * @changelog 2.0.0 initial version
	 * @return
	 * Returns `true` if the byte at the current write position could be written.
	 * @warning
	 * If the buffer is full the byte `byte` will not be inserted and `false` is returned.
	 */
	bool libnapc_RingBuffer_insertByte(libnapc__RingBuffer *ctx, libnapc_u8 byte);

	/*!
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_insertBytes
	 * @name insertBytes
	 * @brief Attempt to insert an array of bytes.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param bytes Bytes to store in circular buffer.
	 * @param bytes_size Size of `bytes` array.
	 * @changelog 2.0.0 initial version
	 * @return
	 * Returns `true` if the bytes were successfully written to the buffer.
	 * @note
	 * If the array `bytes` does not fit in the buffer, no action is performed.
	 */
	bool libnapc_RingBuffer_insertBytes(libnapc__RingBuffer *ctx, const libnapc_u8 *bytes, libnapc_size bytes_size);

	/*!
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_forceInsertByte
	 * @name forceInsertByte
	 * @brief Insert a byte.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param byte Byte to store in circular buffer.
	 * @changelog 2.0.0 initial version
	 * @warning
	 * If the buffer is full the byte `byte` will be forcefully inserted.
	 */
	void libnapc_RingBuffer_forceInsertByte(libnapc__RingBuffer *ctx, libnapc_u8 byte);

	/*!
	 * Resets the write and read position of a buffer.
	 * 
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_reset
	 * @name reset
	 * @brief Reset buffer.
	 * @version 2.0.0
	 * @param ctx Pointer to `libnapc__RingBuffer` instance.
	 * @changelog 2.0.0 initial version
	 * @note
	 * This does not clear the data in the underlying buffer.
	 * 
	 * Only the write and read positions are reset.
	 */
	void libnapc_RingBuffer_reset(libnapc__RingBuffer *ctx);

	/*!
	 * Discards a single byte from the buffer.
	 * 
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_discardByte
	 * @name discardByte
	 * @brief Discard a single byte.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @changelog 2.0.0 initial version
	 */
	void libnapc_RingBuffer_discardByte(libnapc__RingBuffer *ctx);

	/*!
	 * Discards `amount` of bytes from the buffer.
	 * 
	 * @module RingBuffer
	 * @type fn
	 * @fullname libnapc_RingBuffer_discardBytes
	 * @name discardBytes
	 * @brief Discard a number of bytes.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param amount Amount of bytes to discard.
	 * @changelog 2.0.0 initial version
	 * @note
	 * No error checking is done, if buffer is smaller than `amount` the maximum amount
	 * of bytes (i.e. all bytes in the buffer) are discarded.
	 */
	void libnapc_RingBuffer_discardBytes(libnapc__RingBuffer *ctx, libnapc_size amount);
#endif
