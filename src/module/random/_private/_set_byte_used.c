#include <module/random/_private/_random.h>

void PV_napc_random_setByteUsed(napc_size byte_index, bool used) {
	napc_size bin_index = byte_index / 8;
	napc_size bit_pos   = byte_index % 8;
	napc_u8 new_value   = PV_napc_used_random_bytes[bin_index];

	// used means we write a 1
	if (used) {
		new_value |= (1 << bit_pos);
	}
	// !used (free) means we write a 0
	else {
		new_value &= ((1 << bit_pos) ^ 0xFFu);
	}

	PV_napc_used_random_bytes[bin_index] = new_value;
}
