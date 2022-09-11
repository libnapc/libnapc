/*!
 * @name NFWriter:intro
 * @brief No fail binary buffer writer
 */
#if !defined(NAPC_MODULE_NFWRITER_h)
	#define NAPC_MODULE_NFWRITER_h

	#include <libnapc.h>
	#include <napc-magic/napc-magic.h>
	#include <module/writer/writer.h> // napc__Writer

	/*!
	 * @name napc__NFWriter
	 * @module NFWriter
	 * @brief Representation of a no-fail writer.
	 * @version 2.0.0
	 * @opaque
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	typedef struct napc__NFWriter {
		NAPC_MAGIC_MEMBER;
		napc__Writer _writer;
	} napc__NFWriter;

	/*!
	 * @name napc_NFWriter_init
	 * @brief Initialize a no-fail writer.
	 * @version 2.0.0.
	 * @description
	 * Initialize a no-fail writer.
	 * @param ctx Pointer to the napc__NFWriter instance to be initialized.
	 * @param data Pointer to the buffer that we want to write to.
	 * @param data_size Size of `data`.
	 * @changelog 2.0.0 12.04.2022 initial version
	 * @example
	 * napc__NFWriter writer;
	 * char buffer[512];
	 * 
	 * napc_NFWriter_init(&writer, buffer, sizeof(buffer));
	 */
	void napc_NFWriter_init(
		napc__NFWriter *ctx, void *data, napc_size data_size
	);

	/*!
	 * @name napc_NFWriter_create
	 * @brief Create a no-fail writer object.
	 * @version 2.0.0.
	 * @description
	 * Create a no-fail writer.
	 * @param data Pointer to the buffer that we want to write to.
	 * @param data_size Size of `data`.
	 * @changelog 2.0.0 12.04.2022 initial version
	 * @example
	 * char buffer[512];
	 * 
	 * napc__NFWriter writer = napc_NFWriter_create(buffer, sizeof(buffer));
	 */
	napc__NFWriter napc_NFWriter_create(void *data, napc_size data_size);

	/*!
	 * @name napc_NFWriter_moveCurrentOffsetByAmount
	 * @brief Move internal offset.
	 * @version 2.0.0
	 * @description
	 * Move offset by `amount` of bytes.
	 * A negative `offset` is permitted.
	 * @param ctx Pointer to the napc__NFWriter instance.
	 * @param amount The amount.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void napc_NFWriter_moveCurrentOffsetByAmount(
		napc__NFWriter *ctx, napc_ssize amount
	);

	/*!
	 * @name napc_NFWriter_resetCurrentOffset
	 * @brief Reset internal offset.
	 * @version 2.0.0
	 * @description
	 * Reset offset back to zero.
	 * @param ctx Pointer to the napc__NFWriter instance.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void napc_NFWriter_resetCurrentOffset(
		napc__NFWriter *ctx
	);

	/*!
	 * @name napc_NFWriter_writeU8
	 * @brief Write an unsigned integer (8 bits).
	 * @version 2.0.0
	 * @description
	 * Writes the unsigned integer value `value`.
	 * @param ctx Pointer to the napc__NFWriter instance.
	 * @param value Value to be written.
	 * @changelog 2.0.0 12.04.2022 initial version
	 * @example
	 * napc__NFWriter writer;
	 * char buffer[512];
	 * 
	 * napc_NFWriter_init(&writer, buffer, sizeof(buffer));
	 * 
	 * napc_NFWriter_writeU8(&writer, 0xAA);
	 * napc_NFWriter_writeU8(&writer, 0xBB);
	 * 
	 * // buffer[0] is now 0xAA
	 * // buffer[1] is now 0xBB
	 */
	void napc_NFWriter_writeU8(
		napc__NFWriter *ctx, napc_u8 value
	);

	/*!
	 * @name napc_NFWriter_writeU8Array
	 * @brief Write an array unsigned integers (8 bits).
	 * @version 2.0.0
	 * @description
	 * Writes an array of unsigned integer values.
	 * @param ctx Pointer to the napc__NFWriter instance.
	 * @param n_elements The number of elements in `array`.
	 * @param array The array to be written.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void napc_NFWriter_writeU8Array(
		napc__NFWriter *ctx,
		napc_size n_elements,
		const napc_u8 *array
	);

	/*!
	 * @name napc_NFWriter_writeU16BE
	 * @brief Write an unsigned integer (16 bits).
	 * @version 2.0.0
	 * @description
	 * Write the 16 bit unsigned integer value `value` in big endian order.
	 * @param ctx Pointer to the napc__NFWriter instance.
	 * @param value Value to be written.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void napc_NFWriter_writeU16BE(
		napc__NFWriter *ctx, napc_u16 value
	);

	/*!
	 * @name napc_NFWriter_writeU32BE
	 * @brief Write an unsigned integer (32 bits).
	 * @version 2.0.0
	 * @description
	 * Write the 32 bit unsigned integer value `value` in big endian order.
	 * @param ctx Pointer to the napc__NFWriter instance.
	 * @param value Value to be written.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void napc_NFWriter_writeU32BE(
		napc__NFWriter *ctx, napc_u32 value
	);

	/*!
	 * @name napc_NFWriter_writeChar
	 * @brief Write a single character.
	 * @version 2.0.0
	 * @description
	 * Attempts to write the character `value`.
	 * @param ctx Pointer to the napc__NFWriter instance.
	 * @param value Character to be written.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void napc_NFWriter_writeChar(
		napc__NFWriter *ctx, char value
	);

	/*!
	 * @name napc_NFWriter_writeString
	 * @brief Write a string.
	 * @version 2.0.0
	 * @description
	 * Write a string.
	 * @param ctx Pointer to the napc__NFWriter instance.
	 * @param value String to be written.
	 * @notes
	 * No NUL-termination will be placed in the underlying buffer.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void napc_NFWriter_writeString(
		napc__NFWriter *ctx, const char *value
	);

	/*!
	 * @name napc_NFWriter_writeStringFormat
	 * @brief Write a string format.
	 * @version 2.0.0
	 * @description
	 * Write a printf-like formatted string.
	 * @param ctx Pointer to the napc__NFWriter instance.
	 * @param fmt printf()-like format string.
	 * @param ... Values to incorporate into string.
	 * @flags smem
	 * @notes
	 * No NUL-termination will be placed in the underlying buffer.
	 * @changelog 2.0.0 12.04.2022 initial version
	 * @example
	 * napc__NFWriter writer;
	 * char buffer[512];
	 * 
	 * napc_NFWriter_init(&writer, buffer, sizeof(buffer));
	 * 
	 * napc_NFWriter_writeStringFormat(&writer, "Hello %s!", "World!");
	 * 
	 * // the first 12 bytes of `buffer`
	 * // now contain "Hello World!"
	 */
	void napc_NFWriter_writeStringFormat(
		napc__NFWriter *ctx, const char *fmt, ...
	) NAPC_FN_PRINTFLIKE(2, 3);

	/*!
	 * @name napc_NFWriter_getCurrentOffset
	 * @brief Get internal offset.
	 * @version 2.0.0
	 * @description
	 * Get buffer offset from the writer instance.
	 * @return Returns the current buffer offset from the writer instance.
	 * @param ctx Pointer to the napc__NFWriter instance.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	napc_size napc_NFWriter_getCurrentOffset(
		const napc__NFWriter *ctx
	);

	/*!
	 * @name napc_NFWriter_getCurrentAddress
	 * @brief Get current address.
	 * @version 2.0.0
	 * @description
	 * Returns the current address the writer is at `(data + offset)`.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void *napc_NFWriter_getCurrentAddress(
		const napc__NFWriter *ctx
	);

	/*!
	 * @name napc_NFWriter_getStartAddress
	 * @brief Get the start address.
	 * @version 2.0.0
	 * @description
	 * Returns the start address.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void *napc_NFWriter_getStartAddress(
		const napc__NFWriter *ctx
	);

	/*!
	 * @name napc_NFWriter_getEndAddress
	 * @brief Get the last address.
	 * @version 2.0.0
	 * @description
	 * Returns the end address `(data + (size - 1))`.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void *napc_NFWriter_getEndAddress(
		const napc__NFWriter *ctx
	);
#endif
