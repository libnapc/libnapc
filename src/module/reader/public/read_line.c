#include <module/reader/_private/_reader.h>

const char *napc_Reader_readLine(
	napc__Reader *ctx, char *line_buffer, libnapc_size line_buffer_size
) {
	LIBNAPC_MAGIC_ASSERT(napc__Reader, ctx);

	if (!line_buffer_size) {
		LIBNAPC_PANIC(
			"line_buffer_size cannot be zero inside napc_reader__readLine()."
		);
	}

	char ch = 0;
	libnapc_size pos = 0;

	libnapc_mzero(line_buffer, line_buffer_size);

	while (true) {
		// only read char if there is data left to read
		if (!napc_Reader_getRemainingBytes(ctx)) break;
		// attempt to read char
		if (!napc_Reader_readChar(ctx, &ch)) break;

		bool shouldWrite = (line_buffer_size > pos);

		if (ch == '\n') {
			// Terminate line
			if (shouldWrite) line_buffer[pos] = 0;
			++pos;
			break;
		}

		if (shouldWrite) line_buffer[pos] = ch;
		++pos;
	}

	// Nothing has been read
	if (pos == 0) return NULL;

	// Attempt to terminate line
	if (line_buffer_size > pos) line_buffer[pos] = 0;

	// Always terminate line
	line_buffer[line_buffer_size - 1] = 0;

	return line_buffer;
}
