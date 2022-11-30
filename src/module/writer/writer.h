/* <-- add '!' back once ported -->
 * @name Writer:intro
 * @brief Binary buffer writer
 */
#if !defined(LIBNAPC_MODULE_WRITER_h)
	#define LIBNAPC_MODULE_WRITER_h

	#include <libnapc-internal.h>
	#include <libnapc-magic/libnapc-magic.h>
	#include <libnapc-core/libnapc-core.h> // libnapc__AccessFailureMode

	/*!
	 * @module Writer
	 * @type type:opaque
	 * @fullname libnapc__Writer
	 * @brief Representation of a writer.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	typedef struct libnapc__Writer {
		LIBNAPC_MAGIC_MEMBER_DEFINITION

		libnapc__AccessFailureMode _fail_mode;

		libnapc_size _offset;
		libnapc_size size;
		void *data;
	} libnapc__Writer;

	/*!
	 * Initializes a writer.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_init
	 * @name init
	 * @brief Initialize a writer.
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Writer` instance to be initialized.
	 * @param data Pointer to the buffer that we want to write to.
	 * @param data_size Size of `data`.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc__Writer writer;
	 * char buffer[512];
	 * 
	 * libnapc_Writer_init(&writer, buffer, sizeof(buffer));
	 */
	void libnapc_Writer_init(
		libnapc__Writer *ctx, void *data, libnapc_size data_size
	);

	/*!
	 * Creates a writer.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_create
	 * @name create
	 * @brief Create a writer object.
	 * @version 2.0.0
	 * @param data Pointer to the buffer that we want to write to.
	 * @param data_size Size of `data`.
	 * @changelog 2.0.0 initial version
	 * @example
	 * char buffer[512];
	 * 
	 * libnapc__Writer writer = libnapc_Writer_create(buffer, sizeof(buffer));
	 */
	libnapc__Writer libnapc_Writer_create(void *data, libnapc_size data_size);

	/*!
	 * Sets the action to be taken when one of the `write` functions
	 * fails (i.e. returns `false`).
	 * 
	 * The default is to log an error message but can be overwritten by `libnapc_setDefaultAccessFailureMode`.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_setAccessFailureMode
	 * @name setAccessFailureMode
	 * @brief Set action to be taken on access failure.
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Writer` instance.
	 * @param mode The fail mode to set.
	 * @changelog 2.0.0 initial version
	 * @note
	 * For more information refer to the `libnapc__AccessFailureMode` type.
	 */
	void libnapc_Writer_setAccessFailureMode(
		libnapc__Writer *ctx, libnapc__AccessFailureMode mode
	);

	/*!
	 * Moves offset by `amount` of bytes.
	 * A negative `offset` is permitted.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_moveCurrentOffsetByAmount
	 * @name moveCurrentOffsetByAmount
	 * @brief Move internal offset.
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Writer` instance.
	 * @param amount The amount.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_Writer_moveCurrentOffsetByAmount(
		libnapc__Writer *ctx, libnapc_ssize amount
	);

	/*!
	 * Resets offset back to zero.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_resetCurrentOffset
	 * @name resetCurrentOffset
	 * @brief Reset internal offset.
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Writer` instance.
	 * @changelog 2.0.0 initial version
	 */
	void libnapc_Writer_resetCurrentOffset(
		libnapc__Writer *ctx
	);

	/*!
	 * Writes the unsigned integer value `value`.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_writeU8
	 * @name writeU8
	 * @brief Write an unsigned integer (8 bits).
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Writer` instance.
	 * @param value Value to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc__Writer writer;
	 * char buffer[512];
	 * 
	 * libnapc_Writer_init(&writer, buffer, sizeof(buffer));
	 * 
	 * libnapc_Writer_writeU8(&writer, 0xAA);
	 * libnapc_Writer_writeU8(&writer, 0xBB);
	 * 
	 * // buffer[0] is now 0xAA
	 * // buffer[1] is now 0xBB
	 */
	bool libnapc_Writer_writeU8(
		libnapc__Writer *ctx, libnapc_u8 value
	);

	/*!
	 * Writes an array of unsigned integer values.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_writeU8Array
	 * @name writeU8Array
	 * @brief Write an array unsigned integers (8 bits).
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Writer` instance.
	 * @param n_elements The number of elements in `array`.
	 * @param array The array to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_Writer_writeU8Array(
		libnapc__Writer *ctx,
		libnapc_size n_elements,
		const libnapc_u8 *array
	); // needs test

	/*!
	 * Writes the 16 bit unsigned integer value `value` in big endian order.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_writeU16BE
	 * @name writeU16BE
	 * @brief Write an unsigned integer (16 bits).
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Writer` instance.
	 * @param value Value to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_Writer_writeU16BE(
		libnapc__Writer *ctx, libnapc_u16 value
	);

	/*!
	 * Writes the 32 bit unsigned integer value `value` in big endian order.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_writeU32BE
	 * @name writeU32BE
	 * @brief Write an unsigned integer (32 bits).
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Writer` instance.
	 * @param value Value to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_Writer_writeU32BE(
		libnapc__Writer *ctx, libnapc_u32 value
	);

	/*!
	 * Attempts to write the character `value`.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_writeChar
	 * @name writeChar
	 * @brief Write a single character.
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Writer` instance.
	 * @param value Character to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_Writer_writeChar(
		libnapc__Writer *ctx, char value
	);

	/*!
	 * Writes a string.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_writeString
	 * @name writeString
	 * @brief Write a string.
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Writer` instance.
	 * @param value String to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @note
	 * No NUL-termination will be placed in the underlying buffer.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_Writer_writeString(
		libnapc__Writer *ctx, const char *value
	);

	/*!
	 * Writes a printf-like formatted string.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_writeStringFormat
	 * @name writeStringFormat
	 * @brief Write a string format.
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Writer` instance.
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 * @return Returns `true` on success, otherwise `false`.
	 * @note
	 * No NUL-termination will be placed in the underlying buffer.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc__Writer writer;
	 * char buffer[512];
	 * 
	 * libnapc_Writer_init(&writer, buffer, sizeof(buffer));
	 * 
	 * libnapc_Writer_writeStringFormat(&writer, "Hello %s!", "World!");
	 * 
	 * // the first 12 bytes of `buffer`
	 * // now contain "Hello World!"
	 */
	bool libnapc_Writer_writeStringFormat(
		libnapc__Writer *ctx, const char *fmt, ...
	) LIBNAPC_FN_PRINTFLIKE(2, 3);

	/*!
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_getCurrentOffset
	 * @name getCurrentOffset
	 * @brief Get internal offset.
	 * @version 2.0.0
	 * @return Returns the current buffer offset from the writer instance.
	 * @param ctx Pointer to the `libnapc__Writer` instance.
	 * @changelog 2.0.0 initial version
	 */
	libnapc_size libnapc_Writer_getCurrentOffset(
		const libnapc__Writer *ctx
	);

	/*!
	 * Returns the current address the writer is at `(data + offset)`.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_getCurrentAddress
	 * @name getCurrentAddress
	 * @brief Get current address.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	void *libnapc_Writer_getCurrentAddress(
		const libnapc__Writer *ctx
	);

	/*!
	 * Returns the start address.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_getStartAddress
	 * @name getStartAddress
	 * @brief Get the start address.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	void *libnapc_Writer_getStartAddress(
		const libnapc__Writer *ctx
	);

	/*!
	 * Returns the end address `(data + (size - 1))`.
	 * 
	 * @module Writer
	 * @type fn
	 * @fullname libnapc_Writer_getEndAddress
	 * @name getEndAddress
	 * @brief Get the last address.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	void *libnapc_Writer_getEndAddress(
		const libnapc__Writer *ctx
	);
#endif
