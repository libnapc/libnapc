/*!
 * @name Writer:intro
 * @brief Binary buffer writer
 */
#if !defined(NAPC_MODULE_WRITER_h)
	#define NAPC_MODULE_WRITER_h

	#include <libnapc.h>
	#include <napc-magic/napc-magic.h>

	/*!
	 * @name napc__Writer
	 * @brief Representation of a writer.
	 * @version 1.0.0
	 * @notes
	 * Treat this type as opaque.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct {
		NAPC_MAGIC_MEMBER;
		napc_size _offset;
		napc_size size;
		void *data;
		bool no_fail_mode;
	} napc__Writer;

	/*!
	 * @name napc_Writer_init
	 * @brief Initialize a writer.
	 * @version 1.0.0.
	 * @description
	 * Initialize a writer.
	 * @param ctx Pointer to the napc__Writer instance to be initialized.
	 * @param data Pointer to the buffer that we want to write to.
	 * @param data_size Size of `data`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc__Writer writer;
	 * char buffer[512];
	 * 
	 * napc_Writer_init(&writer, buffer, sizeof(buffer));
	 */
	void napc_Writer_init(
		napc__Writer *ctx, void *data, napc_size data_size
	);

	/*!
	 * @name napc_Writer_create
	 * @brief Create a writer object.
	 * @version 1.0.0.
	 * @description
	 * Create a writer.
	 * @param data Pointer to the buffer that we want to write to.
	 * @param data_size Size of `data`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char buffer[512];
	 * 
	 * napc__Writer writer = napc_Writer_create(buffer, sizeof(buffer));
	 */
	napc__Writer napc_Writer_create(void *data, napc_size data_size);

	/**
	 * PRIVATE API CALL
	 * 
	 * @name napc_Writer_setNoFailMode
	 * @brief Set no fail mode.
	 * @version 2.0.0
	 * @description
	 * Sets or clears no fail mode.
	 * In no-fail mode a failed write operation leads to program abortion.
	 * @param ctx Pointer to the napc__Writer instance.
	 * @param mode `true` to set no-fail mode.
	 * @return Returns the previous no-fail mode value.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	bool napc_Writer_setNoFailMode(
		napc__Writer *ctx, bool mode
	);

	/*!
	 * @name napc_Writer_moveCurrentOffsetByAmount
	 * @brief Move internal offset.
	 * @version 1.0.0
	 * @description
	 * Move offset by `amount` of bytes.
	 * A negative `offset` is permitted.
	 * @param ctx Pointer to the napc__Writer instance.
	 * @param amount The amount.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_Writer_moveCurrentOffsetByAmount(
		napc__Writer *ctx, napc_ssize amount
	);

	/*!
	 * @name napc_Writer_resetCurrentOffset
	 * @brief Reset internal offset.
	 * @version 1.0.0
	 * @description
	 * Reset offset back to zero.
	 * @param ctx Pointer to the napc__Writer instance.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void napc_Writer_resetCurrentOffset(
		napc__Writer *ctx
	);

	/*!
	 * @name napc_Writer_writeU8
	 * @brief Write an unsigned integer (8 bits).
	 * @version 1.0.0
	 * @description
	 * Write the unsigned integer value `value`.
	 * @param ctx Pointer to the napc__Writer instance.
	 * @param value Value to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc__Writer writer;
	 * char buffer[512];
	 * 
	 * napc_Writer_init(&writer, buffer, sizeof(buffer));
	 * 
	 * napc_Writer_writeU8(&writer, 0xAA);
	 * napc_Writer_writeU8(&writer, 0xBB);
	 * 
	 * // buffer[0] is now 0xAA
	 * // buffer[1] is now 0xBB
	 */
	bool napc_Writer_writeU8(
		napc__Writer *ctx, napc_u8 value
	);

	/*!
	 * @name napc_Writer_writeU8Array
	 * @brief Write an array unsigned integers (8 bits).
	 * @version 1.0.0
	 * @description
	 * Write an array of unsigned integer values.
	 * @param ctx Pointer to the napc__Writer instance.
	 * @param n_elements The number of elements in `array`.
	 * @param array The array to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_Writer_writeU8Array(
		napc__Writer *ctx,
		napc_size n_elements,
		const napc_u8 *array
	); // needs test

	/*!
	 * @name napc_Writer_writeU16BE
	 * @brief Write an unsigned integer (16 bits).
	 * @version 1.0.0
	 * @description
	 * Write the 16 bit unsigned integer value `value` in big endian order.
	 * @param ctx Pointer to the napc__Writer instance.
	 * @param value Value to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_Writer_writeU16BE(
		napc__Writer *ctx, napc_u16 value
	);

	/*!
	 * @name napc_Writer_writeU32BE
	 * @brief Write an unsigned integer (32 bits).
	 * @version 1.0.0
	 * @description
	 * Write the 32 bit unsigned integer value `value` in big endian order.
	 * @param ctx Pointer to the napc__Writer instance.
	 * @param value Value to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_Writer_writeU32BE(
		napc__Writer *ctx, napc_u32 value
	);

	/*!
	 * @name napc_Writer_writeChar
	 * @brief Write a single character.
	 * @version 1.0.0
	 * @description
	 * Attempts to write the character `value`.
	 * @param ctx Pointer to the napc__Writer instance.
	 * @param value Character to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_Writer_writeChar(
		napc__Writer *ctx, char value
	);

	/*!
	 * @name napc_Writer_writeString
	 * @brief Write a string.
	 * @version 1.0.0
	 * @description
	 * Write a string.
	 * @param ctx Pointer to the napc__Writer instance.
	 * @param value String to be written.
	 * @return Returns `true` on success, otherwise `false`.
	 * @notes
	 * No NUL-termination will be placed in the underlying buffer.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_Writer_writeString(
		napc__Writer *ctx, const char *value
	);

	/*!
	 * @name napc_Writer_writeStringFormat
	 * @brief Write a string format.
	 * @version 1.0.0
	 * @description
	 * Write a printf-like formatted string.
	 * @param ctx Pointer to the napc__Writer instance.
	 * @param fmt printf()-like format string.
	 * @param ... Values to incorporate into string.
	 * @return Returns `true` on success, otherwise `false`.
	 * @flags smem
	 * @notes
	 * No NUL-termination will be placed in the underlying buffer.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc__Writer writer;
	 * char buffer[512];
	 * 
	 * napc_Writer_init(&writer, buffer, sizeof(buffer));
	 * 
	 * napc_Writer_writeStringFormat(&writer, "Hello %s!", "World!");
	 * 
	 * // the first 12 bytes of `buffer`
	 * // now contain "Hello World!"
	 */
	bool napc_Writer_writeStringFormat(
		napc__Writer *ctx, const char *fmt, ...
	) NAPC_FN_PRINTFLIKE(2, 3);

	/*!
	 * @name napc_Writer_getCurrentOffset
	 * @brief Get internal offset.
	 * @version 1.0.0
	 * @description
	 * Get buffer offset from the writer instance.
	 * @return Returns the current buffer offset from the writer instance.
	 * @param ctx Pointer to the napc__Writer instance.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_size napc_Writer_getCurrentOffset(
		const napc__Writer *ctx
	);

	/*!
	 * @name napc_Writer_getCurrentAddress
	 * @brief Get current address.
	 * @version 2.0.0
	 * @description
	 * Returns the current address the writer is at `(data + offset)`.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void *napc_Writer_getCurrentAddress(
		const napc__Writer *ctx
	);

	/*!
	 * @name napc_Writer_getStartAddress
	 * @brief Get the start address.
	 * @version 2.0.0
	 * @description
	 * Returns the start address.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void *napc_Writer_getStartAddress(
		const napc__Writer *ctx
	);

	/*!
	 * @name napc_Writer_getEndAddress
	 * @brief Get the last address.
	 * @version 2.0.0
	 * @description
	 * Returns the end address `(data + (size - 1))`.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void *napc_Writer_getEndAddress(
		const napc__Writer *ctx
	);
#endif
