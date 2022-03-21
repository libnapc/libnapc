#include <module/random/_private/_random.h>

bool PV_napc_random_getByteUsed(napc_size byte_index) {
	napc_size bin_index = byte_index / 8;
	napc_size bit_pos   = byte_index % 8;
	napc_u8 bit_mask    = (1 << bit_pos);

	return !!(PV_napc_used_random_bytes[bin_index] & bit_mask);
}
