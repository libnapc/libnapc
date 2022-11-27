/*!
 * @name Reader:intro
 * @brief Binary buffer reader
 */
#if !defined(LIBNAPC_MODULE_READER_h)
	#define LIBNAPC_MODULE_READER_h

	#include <libnapc-internal.h>
	#include <libnapc-magic/libnapc-magic.h>
	#include <libnapc-core/libnapc-core.h> // libnapc__AccessFailureMode

	/*!
	 * @name napc__Reader
	 * @module Reader
	 * @brief Representation of a reader.
	 * @version 1.0.0
	 * @opaque
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @changelog 2.0.0 21.10.2022 add mode
	 */
	typedef struct libnapc__Reader {
		LIBNAPC_MAGIC_MEMBER;

		libnapc__AccessFailureMode _fail_mode;

		libnapc_size _offset;
		libnapc_size size;
		const void *data;
	} libnapc__Reader;

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
	void libnapc_Reader_init(
		libnapc__Reader *ctx, const void *data, libnapc_size data_size
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
	libnapc__Reader libnapc_Reader_create(const void *data, libnapc_size data_size);

	/*!
	 * @name napc_Reader_setAccessFailureMode
	 * @brief Set action to be taken on access failure.
	 * @version 2.0.0.
	 * @description
	 * Sets the action to be taken when one of the `read` functions
	 * fails (i.e. returns `false`).
	 * 
	 * The default is to log an error message but can be overwritten by `napc_setDefaultAccessFailureMode`.
	 * @param ctx Pointer to the napc__Reader instance.
	 * @param mode The fail mode to set.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @notes
	 * For more information refer to the `napc__AccessFailureMode` type.
	 */
	void libnapc_Reader_setAccessFailureMode(
		libnapc__Reader *ctx, libnapc__AccessFailureMode mode
	);

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
	 * libnapc_u8 buffer[] = {4, 3, 2, 1};
	 * napc__Reader reader;
	 * 
	 * napc_Reader_init(&reader, buffer, sizeof(buffer));
	 * 
	 * libnapc_u8 out;
	 * 
	 * if (napc_Reader_readU8(&reader, &out)) {
	 *     // out has the value '4'
	 * }
	 */
	bool libnapc_Reader_readU8(
		libnapc__Reader *ctx, libnapc_u8 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

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
	bool libnapc_Reader_readU8Array(
		libnapc__Reader *ctx,
		libnapc_size n_elements,
		libnapc_u8 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

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
	 * libnapc_u8 buffer[] = {4, 3, 2, 1};
	 * napc__Reader reader;
	 * 
	 * napc_Reader_init(&reader, buffer, sizeof(buffer));
	 * 
	 * libnapc_u16 out;
	 * 
	 * if (napc_Reader_readU16BE(&reader, &out)) {
	 *     // out has the value 772 (0x0403)
	 * }
	 */
	bool libnapc_Reader_readU16BE(
		libnapc__Reader *ctx, libnapc_u16 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

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
	 * libnapc_u8 buffer[] = {4, 3, 2, 1};
	 * napc__Reader reader;
	 * 
	 * napc_Reader_init(&reader, buffer, sizeof(buffer));
	 * 
	 * libnapc_u32 out;
	 * 
	 * if (napc_Reader_readU32BE(&reader, &out)) {
	 *     // out has the value 67305985 (0x04030201)
	 * }
	 */
	bool libnapc_Reader_readU32BE(
		libnapc__Reader *ctx, libnapc_u32 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

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
	bool libnapc_Reader_readChar(
		libnapc__Reader *ctx, char *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

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
	bool libnapc_Reader_readString(
		libnapc__Reader *ctx,
		libnapc_size str_len,
		char *out,
		libnapc_size out_size
	) LIBNAPC_FN_WARN_UNUSED_RET();

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
	const char *libnapc_Reader_readLine(
		libnapc__Reader *ctx, char *line_buffer, libnapc_size line_buffer_size
	);

	/*!
	 * @name napc_Reader_getCurrentOffset
	 * @brief Get current offset.
	 * @version 2.0.0
	 * @description
	 * Returns the current offset the reader is at.
	 * @changelog 2.0.0 10.04.2022 initial version
	 */
	libnapc_size libnapc_Reader_getCurrentOffset(
		const libnapc__Reader *ctx
	);

	/*!
	 * @name napc_Reader_getRemainingBytes
	 * @brief Get remaining bytes to be read.
	 * @version 2.0.0
	 * @description
	 * Returns the remaining bytes to be read `(size - offset)`.
	 * @changelog 2.0.0 10.04.2022 initial version
	 */
	libnapc_size libnapc_Reader_getRemainingBytes(
		const libnapc__Reader *ctx
	);

	/*!
	 * @name napc_Reader_getCurrentAddress
	 * @brief Get current address.
	 * @version 2.0.0
	 * @description
	 * Returns the current address the reader is at `(data + offset)`.
	 * @changelog 2.0.0 10.04.2022 initial version
	 */
	const void *libnapc_Reader_getCurrentAddress(
		const libnapc__Reader *ctx
	);

	/*!
	 * @name napc_Reader_getStartAddress
	 * @brief Get the start address.
	 * @version 2.0.0
	 * @description
	 * Returns the start address.
	 * @changelog 2.0.0 10.04.2022 initial version
	 */
	const void *libnapc_Reader_getStartAddress(
		const libnapc__Reader *ctx
	);

	/*!
	 * @name napc_Reader_getEndAddress
	 * @brief Get the last address.
	 * @version 2.0.0
	 * @description
	 * Returns the end address `(data + (size - 1))`.
	 * @changelog 2.0.0 10.04.2022 initial version
	 */
	const void *libnapc_Reader_getEndAddress(
		const libnapc__Reader *ctx
	);
#endif
