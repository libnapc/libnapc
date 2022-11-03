/*!
 * @name Reader:intro
 * @brief Binary buffer reader
 */
#if !defined(NAPC_MODULE_READER_h)
	#define NAPC_MODULE_READER_h

	#include <libnapc.h>
	#include <napc-magic/napc-magic.h>

	/*!
	 * @name napc__Reader
	 * @module Reader
	 * @brief Representation of a reader.
	 * @version 1.0.0
	 * @opaque
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct napc__Reader {
		NAPC_MAGIC_MEMBER;
		napc_size _offset;
		napc_size size;
		const void *data;
	} napc__Reader;

	/*!
	 * @name napc_Reader_init
	 * @brief Initialize a reader.
	 * @version 1.0.0
	 * @description
	 * Initialize a reader.
	 * @param ctx Pointer to the napc__Reader instance.
	 * @param data Pointer to the buffer to be read.
	 * @param data_size Size of buffer.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc__Reader reader;
	 * char buffer[512];
	 * 
	 * napc_Reader_init(&reader, buffer, sizeof(buffer));
	 */
	void napc_Reader_init(
		napc__Reader *ctx, const void *data, napc_size data_size
	);

	/*!
	 * @name napc_Reader_create
	 * @brief Create a reader object.
	 * @version 1.0.0
	 * @description
	 * Create a reader.
	 * @param ctx Pointer to the napc__Reader instance.
	 * @param data Pointer to the buffer to be read.
	 * @param data_size Size of `data`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char buffer[512];
	 * 
	 * napc__Reader reader = napc_Reader_create(buffer, sizeof(buffer));
	 */
	napc__Reader napc_Reader_create(const void *data, napc_size data_size);

	/*!
	 * @name napc_Reader_readU8
	 * @brief Read an unsigned integer (8 bits).
	 * @version 1.0.0
	 * @description
	 * Read an unsigned integer (8 bit) from buffer.
	 * @param ctx Pointer to napc__Reader instance.
	 * @param out Pointer to store result.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @return Returns `true` on success, `false` otherwise.
	 * @example
	 * napc_u8 buffer[] = {4, 3, 2, 1};
	 * napc__Reader reader;
	 * 
	 * napc_Reader_init(&reader, buffer, sizeof(buffer));
	 * 
	 * napc_u8 out;
	 * 
	 * if (napc_Reader_readU8(&reader, &out)) {
	 *     // out has the value '4'
	 * }
	 */
	bool napc_Reader_readU8(
		napc__Reader *ctx, napc_u8 *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_Reader_readU8Array
	 * @brief Read an array of unsigned integers (8 bits).
	 * @version 1.0.0
	 * @description
	 * Read an array of unsigned integers (8 bit) from buffer.
	 * @param ctx Pointer to napc__Reader instance.
	 * @param n_elements Number of elements to read.
	 * @param out Array to store bytes.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_Reader_readU8Array(
		napc__Reader *ctx,
		napc_size n_elements,
		napc_u8 *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_Reader_readU16BE
	 * @brief Read an unsigned integer (16 bits).
	 * @version 1.0.0
	 * @description
	 * Read an unsigned integer (16 bit) in big endian order from buffer.
	 * @param ctx Pointer to napc__Reader instance.
	 * @param out Pointer to store result.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u8 buffer[] = {4, 3, 2, 1};
	 * napc__Reader reader;
	 * 
	 * napc_Reader_init(&reader, buffer, sizeof(buffer));
	 * 
	 * napc_u16 out;
	 * 
	 * if (napc_Reader_readU16BE(&reader, &out)) {
	 *     // out has the value 772 (0x0403)
	 * }
	 */
	bool napc_Reader_readU16BE(
		napc__Reader *ctx, napc_u16 *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_Reader_readU32BE
	 * @brief Read an unsigned integer (32 bits).
	 * @version 1.0.0
	 * @description
	 * Read an unsigned integer (32 bit) in big endian order from buffer.
	 * @param ctx Pointer to napc__Reader instance.
	 * @param out Pointer to store result.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u8 buffer[] = {4, 3, 2, 1};
	 * napc__Reader reader;
	 * 
	 * napc_Reader_init(&reader, buffer, sizeof(buffer));
	 * 
	 * napc_u32 out;
	 * 
	 * if (napc_Reader_readU32BE(&reader, &out)) {
	 *     // out has the value 67305985 (0x04030201)
	 * }
	 */
	bool napc_Reader_readU32BE(
		napc__Reader *ctx, napc_u32 *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_Reader_readChar
	 * @brief Read a single character.
	 * @version 1.0.0
	 * @description
	 * Read a character (8 bit) from buffer.
	 * @param ctx Pointer to napc__Reader instance.
	 * @param out Pointer to store result.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_Reader_readChar(
		napc__Reader *ctx, char *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_Reader_readString
	 * @brief Read a string.
	 * @version 1.0.0
	 * @description
	 * Read a string from buffer.
	 * @param ctx Pointer to napc__Reader instance.
	 * @param str_len Length of string to be read.
	 * @param out Pointer to store result.
	 * @param out_size Size of `out`.
	 * @return Returns `true` on success, `false` otherwise.
	 * @notes
	 * Resulting string (that is placed in `out`) is always NUL-terminated.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_Reader_readString(
		napc__Reader *ctx,
		napc_size str_len,
		char *out,
		napc_size out_size
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_Reader_readLine
	 * @brief Read a line.
	 * @version 1.0.0
	 * @description
	 * Read a line from buffer.
	 * @param ctx Pointer to napc__Reader instance.
	 * @param line_buffer Buffer to place line into.
	 * @param line_buffer_size Size of the line buffer.
	 * @return Returns `line_buffer` if a line was parsed, `NULL` otherwise.
	 * @notes
	 * The resulting string in `line_buffer` will always be NUL-terminated.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char line_buffer[128];
	 * napc__Reader reader;
	 * const char *str = "First line\nSecond line\nThird line";
	 * 
	 * napc_Reader_init(&reader, str, napc_strlen(str));
	 * 
	 * while (true) {
	 *     const char *current_line = napc_Reader_readLine(&reader, line_buffer, sizeof(line_buffer));
	 * 
	 *     if (!current_line) break;
	 * 
	 *     napc_printf("Read line: %s", current_line);
	 * }
	 */
	const char *napc_Reader_readLine(
		napc__Reader *ctx, char *line_buffer, napc_size line_buffer_size
	);

	/*!
	 * @name napc_Reader_getCurrentOffset
	 * @brief Get current offset.
	 * @version 2.0.0
	 * @description
	 * Returns the current offset the reader is at.
	 * @changelog 2.0.0 10.04.2022 initial version
	 */
	napc_size napc_Reader_getCurrentOffset(
		const napc__Reader *ctx
	);

	/*!
	 * @name napc_Reader_getRemainingBytes
	 * @brief Get remaining bytes to be read.
	 * @version 2.0.0
	 * @description
	 * Returns the remaining bytes to be read.
	 * @changelog 2.0.0 10.04.2022 initial version
	 */
	napc_size napc_Reader_getRemainingBytes(
		const napc__Reader *ctx
	);

	/*!
	 * @name napc_Reader_getCurrentAddress
	 * @brief Get current address.
	 * @version 2.0.0
	 * @description
	 * Returns the current address the reader is at `(data + offset)`.
	 * @changelog 2.0.0 10.04.2022 initial version
	 */
	const void *napc_Reader_getCurrentAddress(
		const napc__Reader *ctx
	);

	/*!
	 * @name napc_Reader_getStartAddress
	 * @brief Get the start address.
	 * @version 2.0.0
	 * @description
	 * Returns the start address.
	 * @changelog 2.0.0 10.04.2022 initial version
	 */
	const void *napc_Reader_getStartAddress(
		const napc__Reader *ctx
	);

	/*!
	 * @name napc_Reader_getEndAddress
	 * @brief Get the last address.
	 * @version 2.0.0
	 * @description
	 * Returns the end address `(data + (size - 1))`.
	 * @changelog 2.0.0 10.04.2022 initial version
	 */
	const void *napc_Reader_getEndAddress(
		const napc__Reader *ctx
	);
#endif
