#include <napc-utils/_private/_napc-utils.h>

void libnapc_mzero(void *data, libnapc_size data_size) {
	memset(data, 0, data_size);
}
