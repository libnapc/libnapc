#include <napc-utils/_private/_napc-utils.h>

bool libnapc_memeql(const void *data1, const void *data2, libnapc_size data_size) {
	return memcmp(data1, data2, data_size) == 0;
}
