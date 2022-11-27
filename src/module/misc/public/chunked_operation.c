#include <module/misc/_private/_misc.h>

bool libnapc_misc_chunkedOperation(
	const void *data, libnapc_size data_size, libnapc_size chunk_size,
	napc_misc_ChunkedOperationCallback fn, void *fn_context
) {
	const unsigned char *ptr = data;
	libnapc_size bytes_left_to_process = data_size;
	libnapc_size current_chunk_size = chunk_size;

	while (bytes_left_to_process > 0) {
		if (current_chunk_size > bytes_left_to_process) {
			PV_NAPC_MISC_VERBOSE(
				"Halving chunk_size=%" LIBNAPC_SIZE_PRINT_DEC,
				current_chunk_size
			);

			current_chunk_size /= 2;

			// Make sure chunk size never is zero
			if (!current_chunk_size) current_chunk_size = 1;

			continue;
		}

		libnapc_ssize result = fn(ptr, current_chunk_size, fn_context);

		// Impartial operation
		if (result != (libnapc_ssize)current_chunk_size) {
			PV_NAPC_MISC_ERROR(
				"Impartial chunk operation (current_chunk_size=%" LIBNAPC_SIZE_PRINT_DEC ",result=%" LIBNAPC_SSIZE_PRINT_DEC ")",
				current_chunk_size, result
			);

			return false;
		}

		ptr += current_chunk_size;

		bytes_left_to_process -= current_chunk_size;
	}

	return true;
}
