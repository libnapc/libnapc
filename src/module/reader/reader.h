/* <-- add '!' back once ported -->
 * @name Reader:intro
 * @brief Binary buffer reader
 */
#if !defined(LIBNAPC_MODULE_READER_h)
	#define LIBNAPC_MODULE_READER_h

	#include <libnapc-internal.h>
	#include <libnapc-magic/libnapc-magic.h>
	#include <libnapc-core/libnapc-core.h> // libnapc__AccessFailureMode

	/*!
	 * @module Reader
	 * @type type:opaque
	 * @fullname libnapc__Reader
	 * @brief Representation of a reader.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	typedef struct libnapc__Reader {
		LIBNAPC_MAGIC_MEMBER;

		libnapc__AccessFailureMode _fail_mode;

		libnapc_size _offset;
		libnapc_size size;
		const void *data;
	} libnapc__Reader;

	/*!
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_init
	 * @name init
	 * @brief Initialize a reader.
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Reader` instance.
	 * @param data Pointer to the buffer to be read.
	 * @param data_size Size of buffer.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc__Reader reader;
	 * char buffer[512];
	 * 
	 * libnapc_Reader_init(&reader, buffer, sizeof(buffer));
	 */
	void libnapc_Reader_init(
		libnapc__Reader *ctx, const void *data, libnapc_size data_size
	);

	/*!
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_create
	 * @name create
	 * @brief Create a reader object.
	 * @version 2.0.0
	 * @param ctx Pointer to the `libnapc__Reader` instance.
	 * @param data Pointer to the buffer to be read.
	 * @param data_size Size of `data`.
	 * @changelog 2.0.0 initial version
	 * @example
	 * char buffer[512];
	 * 
	 * libnapc__Reader reader = libnapc_Reader_create(buffer, sizeof(buffer));
	 */
	libnapc__Reader libnapc_Reader_create(const void *data, libnapc_size data_size);

	/*!
	 * Sets the action to be taken when one of the `read` functions
	 * fails (i.e. returns `false`).
	 * 
	 * The default is to log an error message but can be overwritten by `libnapc_setDefaultAccessFailureMode`.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_setAccessFailureMode
	 * @name setAccessFailureMode
	 * @brief Set action to be taken on access failure.
	 * @version 2.0.0.
	 * @param ctx Pointer to the `libnapc__Reader` instance.
	 * @param mode The fail mode to set.
	 * @changelog 2.0.0 initial version
	 * @note
	 * For more information refer to the `libnapc__AccessFailureMode` type.
	 */
	void libnapc_Reader_setAccessFailureMode(
		libnapc__Reader *ctx, libnapc__AccessFailureMode mode
	);

	/*!
	 * Reads an unsigned integer (8 bit) from buffer.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_readU8
	 * @name readU8
	 * @brief Read an unsigned integer (8 bits).
	 * @version 2.0.0
	 * @param ctx Pointer to `libnapc__Reader` instance.
	 * @param out Pointer to store result.
	 * @changelog 2.0.0 initial version
	 * @return Returns `true` on success, `false` otherwise.
	 * @example
	 * libnapc_u8 buffer[] = {4, 3, 2, 1};
	 * libnapc__Reader reader;
	 * 
	 * libnapc_Reader_init(&reader, buffer, sizeof(buffer));
	 * 
	 * libnapc_u8 out;
	 * 
	 * if (libnapc_Reader_readU8(&reader, &out)) {
	 *     // out has the value '4'
	 * }
	 */
	bool libnapc_Reader_readU8(
		libnapc__Reader *ctx, libnapc_u8 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Reads an array of unsigned integers (8 bit) from buffer.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_readU8Array
	 * @name readU8Array
	 * @brief Read an array of unsigned integers (8 bits).
	 * @version 2.0.0
	 * @param ctx Pointer to `libnapc__Reader` instance.
	 * @param n_elements Number of elements to read.
	 * @param out Array to store bytes.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_Reader_readU8Array(
		libnapc__Reader *ctx,
		libnapc_size n_elements,
		libnapc_u8 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Reads an unsigned integer (16 bit) in big endian order from buffer.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_readU16BE
	 * @name readU16BE
	 * @brief Read an unsigned integer (16 bits).
	 * @version 2.0.0
	 * @param ctx Pointer to `libnapc__Reader` instance.
	 * @param out Pointer to store result.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 buffer[] = {4, 3, 2, 1};
	 * libnapc__Reader reader;
	 * 
	 * libnapc_Reader_init(&reader, buffer, sizeof(buffer));
	 * 
	 * libnapc_u16 out;
	 * 
	 * if (libnapc_Reader_readU16BE(&reader, &out)) {
	 *     // out has the value 772 (0x0403)
	 * }
	 */
	bool libnapc_Reader_readU16BE(
		libnapc__Reader *ctx, libnapc_u16 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Reads an unsigned integer (32 bit) in big endian order from buffer.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_readU32BE
	 * @name readU32BE
	 * @brief Read an unsigned integer (32 bits).
	 * @version 2.0.0
	 * @param ctx Pointer to `libnapc__Reader` instance.
	 * @param out Pointer to store result.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 buffer[] = {4, 3, 2, 1};
	 * libnapc__Reader reader;
	 * 
	 * libnapc_Reader_init(&reader, buffer, sizeof(buffer));
	 * 
	 * libnapc_u32 out;
	 * 
	 * if (libnapc_Reader_readU32BE(&reader, &out)) {
	 *     // out has the value 67305985 (0x04030201)
	 * }
	 */
	bool libnapc_Reader_readU32BE(
		libnapc__Reader *ctx, libnapc_u32 *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Reads a character (8 bit) from buffer.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_readChar
	 * @name readChar
	 * @brief Read a single character.
	 * @version 2.0.0
	 * @param ctx Pointer to `libnapc__Reader` instance.
	 * @param out Pointer to store result.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_Reader_readChar(
		libnapc__Reader *ctx, char *out
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Reads a string from buffer.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_readString
	 * @name readString
	 * @brief Read a string.
	 * @version 2.0.0
	 * @param ctx Pointer to `libnapc__Reader` instance.
	 * @param str_len Length of string to be read.
	 * @param out Pointer to store result.
	 * @param out_size Size of `out`.
	 * @return Returns `true` on success, `false` otherwise.
	 * @note
	 * Resulting string (that is placed in `out`) is always NUL-terminated.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_Reader_readString(
		libnapc__Reader *ctx,
		libnapc_size str_len,
		char *out,
		libnapc_size out_size
	) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Reads a single line from buffer.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_readLine
	 * @name readLine
	 * @brief Read a line.
	 * @version 2.0.0
	 * @param ctx Pointer to `libnapc__Reader` instance.
	 * @param line_buffer Buffer to place line into.
	 * @param line_buffer_size Size of the line buffer.
	 * @return Returns `line_buffer` if a line was parsed, `NULL` otherwise.
	 * @note
	 * The resulting string in `line_buffer` will always be NUL-terminated.
	 * @changelog 2.0.0 initial version
	 * @example
	 * char line_buffer[128];
	 * libnapc__Reader reader;
	 * const char *str = "First line\nSecond line\nThird line";
	 * 
	 * libnapc_Reader_init(&reader, str, libnapc_strlen(str));
	 * 
	 * while (true) {
	 *     const char *current_line = libnapc_Reader_readLine(&reader, line_buffer, sizeof(line_buffer));
	 * 
	 *     if (!current_line) break;
	 * 
	 *     libnapc_printf("Read line: %s", current_line);
	 * }
	 */
	const char *libnapc_Reader_readLine(
		libnapc__Reader *ctx, char *line_buffer, libnapc_size line_buffer_size
	);

	/*!
	 * Returns the current offset the reader is at.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_getCurrentOffset
	 * @name getCurrentOffset
	 * @brief Get current offset.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	libnapc_size libnapc_Reader_getCurrentOffset(
		const libnapc__Reader *ctx
	);

	/*!
	 * Returns the remaining bytes to be read `(size - offset)`.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_getRemainingBytes
	 * @name getRemainingBytes
	 * @brief Get remaining bytes to be read.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	libnapc_size libnapc_Reader_getRemainingBytes(
		const libnapc__Reader *ctx
	);

	/*!
	 * Returns the current address the reader is at `(data + offset)`.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_getCurrentAddress
	 * @name getCurrentAddress
	 * @brief Get current address.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	const void *libnapc_Reader_getCurrentAddress(
		const libnapc__Reader *ctx
	);

	/*!
	 * Returns the start address.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_getStartAddress
	 * @name getStartAddress
	 * @brief Get the start address.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	const void *libnapc_Reader_getStartAddress(
		const libnapc__Reader *ctx
	);

	/*!
	 * Returns the end address `(data + (size - 1))`.
	 * 
	 * @module Reader
	 * @type fn
	 * @fullname libnapc_Reader_getEndAddress
	 * @name getEndAddress
	 * @brief Get the last address.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	const void *libnapc_Reader_getEndAddress(
		const libnapc__Reader *ctx
	);
#endif
