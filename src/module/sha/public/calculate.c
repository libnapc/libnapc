#include <module/sha/_private/_sha.h>

bool napc_sha_calculate(
	const void *buffer, libnapc_size buffer_size,
	char *out, libnapc_size out_size
) {
	if (!out || 64 >= out_size) {
		return false;
	}

	H5P9SL_SHA256_HASH digest;

	H5P9SL_Sha256Calculate(
		// buffer
		buffer, buffer_size,
		// output digest
		&digest
	);

	napc__Writer writer = napc_Writer_create(out, out_size);

	for (libnapc_size i = 0; i < 32; ++i) {
		libnapc_u8 byte = digest.bytes[i];

		bool result = napc_Writer_writeStringFormat(
			&writer, "%2.2x", byte
		);

		if (!result) return false;
	}

	// terminate output string
	if (!napc_Writer_writeChar(&writer, 0)) return false;

	return true;
}
